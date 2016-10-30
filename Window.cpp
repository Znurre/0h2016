#include <QKeyEvent>
#include <QPainter>

#include "Window.h"
#include "IDrawable.h"

Window::Window()
	: m_positionProvider(*this)
	, m_bucket(m_positionProvider)
	, m_spawner(m_positionProvider, m_stateHandler, m_bucket)
{
	m_timer.start();
}

void Window::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);

	QPainter painter(this);

	const QRect &viewport = painter.viewport();

	painter.fillRect(viewport, Qt::black);

	switch (m_stateHandler.state())
	{
		case StateHandler::Running:
		{
			if (m_timer.elapsed())
			{
				const long delta = m_timer.restart();

				m_spawner.update(delta);
				m_bucket.update(delta);
			}

			m_spawner.draw(painter);
			m_bucket.draw(painter);

			return update();
		}

		case StateHandler::GameOver:
		{
			painter.setPen(Qt::white);
			painter.drawText(viewport, Qt::AlignCenter, "Game Over");

			break;
		}
	}
}

void Window::keyPressEvent(QKeyEvent *event)
{
	if (!event->isAutoRepeat())
	{
		m_bucket.move();
	}
}
