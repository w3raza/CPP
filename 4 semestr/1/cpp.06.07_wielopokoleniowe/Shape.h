#ifndef _SHAPE_H_
#define _SHAPE_H_
	
class Shape
{
public:
	double GetX() const;
	double GetY() const;
	void SetX(double x);
	void SetY(double y);
	double Pole() const
	{ return 0.0; }

protected:
	double m_x,m_y;
};
inline double Shape::GetX() const
{
	return m_x;
}

/////////////////////////////////////////////////////////////////////////
inline double Shape::GetY() const
{
	return m_y;
}

/////////////////////////////////////////////////////////////////////////
inline void Shape::SetX(double x)
{
	m_x = x;
}

/////////////////////////////////////////////////////////////////////////
inline void Shape::SetY(double y)
{
	m_y = y;
}

/////////////////////////////////////////////////////////////////////////
#endif