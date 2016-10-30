#include "Bucket.h"
#include "PositionProvider.h"

Bucket::Bucket(PositionProvider &positionProvider)
	: m_positionProvider(positionProvider)
	, m_index(2)
{

}

int Bucket::index() const
{
	return m_index;
}

void Bucket::move()
{
	m_index = (m_index + 1) % 5;
}

void Bucket::draw(QPainter &painter)
{
	const int x = m_positionProvider.getPosition(m_index);
	const int y = m_positionProvider.getBottom();
	const int w = m_positionProvider.getBucketWidth();

	const QRect rect(x, y, w, 20);

	painter.fillRect(rect, Qt::white);
}

bool Bucket::update(long delta)
{
	Q_UNUSED(delta);

	return true;
}
