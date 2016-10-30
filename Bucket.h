#ifndef BUCKET_H
#define BUCKET_H

#include "IDrawable.h"

class PositionProvider;

class Bucket : public IDrawable
{
	public:
		Bucket(PositionProvider &positionProvider);

		int index() const;

		void move();

		void draw(QPainter &painter) override;
		bool update(long delta) override;

	private:
		PositionProvider &m_positionProvider;

		int m_index;
};

#endif // BUCKET_H
