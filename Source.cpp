#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define PI 3.14159
using namespace std;
class CGraphicObject
{
protected:
	CGraphicObject() {}
public:
	virtual double CalcArea() const = 0;
	virtual double CalcPerimeter() const = 0;
	virtual void Output() const = 0;
	virtual bool less(const CGraphicObject* oGraphicObject)
		const = 0;
};
class CRectangle : public CGraphicObject
{
private:
	int m_height;
	int m_width;
public:
	CRectangle(const int h, const int w) :
		m_height(h), m_width(w) {}
	double CalcArea() const {
		return m_height * m_width; }
	double CalcPerimeter() const {
		return (m_height * 2) + (m_width * 2); }
	bool less(const CGraphicObject* oGraphicObject) const {
		return CalcArea() < oGraphicObject->CalcArea();
	}
	void Output() const {
		cout << "Rectangle height and width: = " << m_height << " "
			<< m_width << " : " << CalcArea() << endl;
		cout << "Rectangle perimeter: " << CalcPerimeter() << endl;
		cout << setfill('#') << setw(10) << endl;
	}

	int Get_Width() const { return m_width; }
};
class CSquare :public CRectangle {
public:
	CSquare(const int var) : CRectangle(var, var) {}
	void Output() const {
		cout << "Square var = " << Get_Width() << " : " <<
			CalcArea() << endl;
		cout << "Square perimeter = " << CalcPerimeter() << endl;
		cout << setfill('#') << setw(10) << endl;
	}
};
class CCircle : public CGraphicObject {
private:
	int m_radius;
public:
	CCircle(const int radius) : m_radius(radius) {}
	double CalcArea() const {
		return PI * pow(m_radius, 2);
	}
	double CalcPerimeter() const {
		return (2 * PI * m_radius);
	}
	bool less(const CGraphicObject* oGraphicObject) const
	{
		return CalcArea() < oGraphicObject->CalcArea();
	}
	void Output() const {
		cout << "Circle radius = " << m_radius << " : " <<
			CalcArea() << endl;
		cout << "Circle perimeter = " << CalcPerimeter() << endl;
		cout << setfill('#') << setw(10) << endl;
	}
};
class CTriangle : public CGraphicObject {
private:
	double m_dSideA, m_dSideB, m_dSideC;
public:
	CTriangle(const double sideA, const double sideB, const double sideC) :
		m_dSideA(sideA), m_dSideB(sideB), m_dSideC(sideC) {}
	double CalcArea() const {
		double s = (m_dSideA + m_dSideB + m_dSideC) / 2.0;
		return sqrt(s*(s - m_dSideA) * (s - m_dSideB)*(s - m_dSideC));
	}
	double CalcPerimeter() const {
		return m_dSideA + m_dSideB + m_dSideC;
	}
	// проверка дали лицето на сегашния обект е по-малък от обекта подаден като параметър
	// тъй като е със "const" няма право да модифицира член функциите на обекта.
	bool less(const CGraphicObject* oGraphicObject) const {  
		return CalcArea() < oGraphicObject->CalcArea();
	}
	void Output() const {
		cout << "Triangle with sides of length " << m_dSideA << ", " << m_dSideB << ", and " << m_dSideC
			<< " has an area of " << CalcArea() << "." << endl;
		cout << "Triangle's perimeter = " << CalcPerimeter() << endl;
		cout << setfill('#') << setw(10) << endl;

	}

};
class CGraphicObjectSet {
private:
	vector<CGraphicObject*> m_vObjects;
public:
	void AddGraphicObject(CGraphicObject* graphicObject) {
		m_vObjects.push_back(graphicObject);
	}
	void Output() const {
		for (const auto&graphicObject : m_vObjects)
		{
			graphicObject->Output();
		}
	}
	void Clear() {
		m_vObjects.clear();
	}

};

int main()
{
	CGraphicObjectSet set;
	set.AddGraphicObject(new CRectangle(2, 3));
	set.AddGraphicObject(new CSquare(4));
	set.AddGraphicObject(new CCircle(5));
	set.AddGraphicObject(new CTriangle(3, 4, 5));
	set.Output();
	set.Clear();
}