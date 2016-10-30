#ifndef WINDOW_H
#define WINDOW_H

#include <QElapsedTimer>
#include <QRasterWindow>

#include "Bucket.h"
#include "FruitSpawner.h"
#include "PositionProvider.h"
#include "StateHandler.h"

class IDrawable;

class Window : public QRasterWindow
{
	public:
		Window();

	private:
		void paintEvent(QPaintEvent *event) override;
		void keyPressEvent(QKeyEvent *event) override;

		QElapsedTimer m_timer;

		PositionProvider m_positionProvider;
		StateHandler m_stateHandler;
		Bucket m_bucket;
		FruitSpawner m_spawner;
};

#endif // WINDOW_H
