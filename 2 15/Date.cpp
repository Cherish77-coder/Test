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
void Date:: Print()
{
	cout <<_year << "/" << _month << "/" << _day << endl;
}
bool Date::CheckDate()
{
	if (_year < 0 || _month>13 || _month < 0 || _day < 0 || _day>32)
		return false;
	else if (GetMonthDay(_year, _month) < _day)
		return false;
	return true;
}
bool Date::operator<(const Date& d)
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
bool Date::operator<=(const Date& d)
{
	if (_year > d._year)
	{
		return false;
	}
	else if (_month > d._month)
	{
		return false;
	}
	else if (_day > d._day)
	{
		return false;
	}
	return true;
}
bool Date::operator>(const Date& d)
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
bool Date::operator>=(const Date& d)
{
	if (_year < d._year)
	{
		return false;
	}
	else if (_month < d._month)
	{
		return false;
	}
	else if (_day < d._day)
	{
		return false;
	}
	return true;
}
bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}
bool Date::operator!=(const Date& d)
{
	return !(_year == d._year && _month == d._month && _day == d._day);
}
Date& Date::operator+=(int day)
{
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
Date Date::operator+(int day)
{
	Date temp = *this;
	int ret = day;
	while (ret--)
	{
		int get = GetMonthDay(temp._year, temp._month);
		if (temp._day < get)
		{
			temp._day++;
		}
		else
		{
			if (temp._month < 12)
			{
				temp._month++;
				temp._day = 1;
			}
			else
			{
				temp._year++;
				temp._month = temp._day = 1;
			}
		}
	}
	return temp;
}
Date& Date::operator-=(int day)
{
	int ret = day;
	while (ret--)
	{
		//int get = GetMonthDay(_year, _month);
		if (_day >1)
		{
			_day--;
		}
		else
		{
			if (_month >1)
			{
				_month--;
				_day = GetMonthDay(_year, _month);
			}
			else if(_month==1&&_year>0)
			{
				_year--;
				_month = 12;
				_day= GetMonthDay(_year, _month);
			}
		}
	}
	return *this;
}
Date Date::operator-(int day)
{
	Date temp = *this;
	int ret = day;
	while (ret--)
	{
		//int get = GetMonthDay(_year, _month);
		if (temp._day > 1)
		{
			temp._day--;
		}
		else
		{
			if (temp._month > 1)
			{
				temp._month--;
				temp._day = GetMonthDay(temp._year, temp._month);
			}
			else if (temp._month == 1 && temp._year > 0)
			{
				temp._year--;
				temp._month = 12;
				temp._day = GetMonthDay(temp._year, temp._month);
			}
		}
	}
	return temp;;
}
int Date::operator-(const Date& d)
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
	int day = GetMonthDay(_year, _month);
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
	return d1;
}
Date& Date::operator--()
{
	if (_day == 1)
	{
		if (_month > 1)
		{
			_month--;
			_day = GetMonthDay(_year,_month);
		}
		else
		{
			_year--;
			_month = 12;
			_day = 31;
		}
	}
	else
	{
		_day--;
	}
	return *this;
}
Date Date::operator--(int)
{
	Date d1(*this);
	if (_day == 1)
	{
		if (_month > 1)
		{
			_month--;
			_day = GetMonthDay(_year, _month);
		}
		else
		{
			_year--;
			_month = 12;
			_day = 31;
		}
	}
	else
	{
		_day--;
	}
	return d1;
}