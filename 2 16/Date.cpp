#include"Date.h"
Date::Date(int year , int month , int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (!CheckDate())
	{
		cout << "日期非法" << endl;
	}
}
void Date:: Print() const
{
	cout <<_year << "/" << _month << "/" << _day << endl;
}
bool Date::CheckDate() const
{
	if (_year < 0 || _month>13 || _month < 0 || _day < 0 || _day>32)
		return false;
	else if (GetMonthDay(_year, _month) < _day)
		return false;
	return true;
}
bool Date::operator<(const Date& d) const
{
	if (_year < d._year)
		return true;
	else if (_year == d._year)
	{
		if (_month < d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day < d._day)
			{
				return true;
			}
		}
	}
	
		return false;
}
bool Date::operator<=(const Date& d) const
{
	return *this < d || *this == d;
}
bool Date::operator>(const Date& d) const
{
	if (_year > d._year)
		return true;
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}

	return false;
}
bool Date::operator>=(const Date& d) const
{
	return *this >d || *this == d;
}
bool Date::operator==(const Date& d) const
{
	return _year == d._year && _month == d._month && _day == d._day;
}
bool Date::operator!=(const Date& d) const
{
	return !(_year == d._year && _month == d._month && _day == d._day);
}
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= (-day);
		return *this;
	}
	int ret = day;
	while (ret--)
	{
		int get = GetMonthDay(_year, _month);
		if (_day < get)
		{
			_day++;
		}
		else
		{
			if (_month < 12)
			{
				_month++;
				_day = 1;
			}
			else
			{
				_year++;
				_month = _day = 1;
			}
		}
	}
	return *this;
}
Date Date::operator+(int day) const
{
	Date temp = *this;
	if (day < 0)
	{
		temp -= (-day);
		return temp;
	}
	temp += day;
	return temp;
}
//Date Date::operator+(int day)
//{
//	Date temp = *this;
//	int ret = day;
//	while (ret--)
//	{
//		int get = GetMonthDay(temp._year, temp._month);
//		if (temp._day < get)
//		{
//			temp._day++;
//		}
//		else
//		{
//			if (temp._month < 12)
//			{
//				temp._month++;
//				temp._day = 1;
//			}
//			else
//			{
//				temp._year++;
//				temp._month = temp._day = 1;
//			}
//		}
//	}
//	return temp;
//}
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		*this += (-day);
		return *this;
	}
	_day -= day;
	while (_day < 0)
	{
		if (_month > 1)
		{
			_month--;
			_day += GetMonthDay(_year, _month);
		}
		else if (_month == 1)
		{
			_year--;
			_month = 12;
			_day += GetMonthDay(_year, _month);
		}
	}
	return *this;
}
Date Date::operator-(int day) const
{
	Date temp = *this;
	if (day < 0)
	{
		temp += (-day);
		return temp;
	}
	temp -= day;
	return temp;
}
//Date Date::operator-(int day)
//{
//	Date temp = *this;
//	int ret = day;
//	while (ret--)
//	{
//		//int get = GetMonthDay(_year, _month);
//		if (temp._day > 1)
//		{
//			temp._day--;
//		}
//		else
//		{
//			if (temp._month > 1)
//			{
//				temp._month--;
//				temp._day = GetMonthDay(temp._year, temp._month);
//			}
//			else if (temp._month == 1 && temp._year > 0)
//			{
//				temp._year--;
//				temp._month = 12;
//				temp._day = GetMonthDay(temp._year, temp._month);
//			}
//		}
//	}
//	return temp;;
//}
int Date::operator-(const Date& d) const
{
	Date d1(*this);
	Date d2(d);
	int ret = 0;
	if (d1 > d2)
	{
		while (d1 != d2)
		{
			d1-=1;
			ret++;
		}
	}
	else if (d1 == d2)
		return 0;
	else {
		while (d1 != d2)
		{
			d2-=1;
			ret++;
		}
	}
	return ret;
}
Date& Date::operator++()
{
	int day = GetMonthDay(_year,_month);
	if (_day < day)
	{
		_day++;
	}
	else if (_month < 12)
	{
		_month++;
		_day = 1;
	}
	else if (_month == 12)
	{
		_year++;
		_month = _day = 1;
	}
	return *this;
}
Date Date::operator++(int)
{
	Date d1(*this);
	*this += 1;
	return d1;
}
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int)
{
	Date d1(*this);
	*this -= 1;
	return d1;
}
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
} 
istream& operator>>(istream& in, Date& d)
{
	cout << "请依次输入年月日:>";
	in >> d._year >> d._month >> d._day;
	return in;
}