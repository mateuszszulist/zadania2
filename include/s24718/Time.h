#include <string>
#include <iostream>
#include <iomanip>

enum class Time_of_day
{
	rano,
	dzien,
	wieczor,
	noc,
};

struct Time 
{
	int godzina;
	int minuta;
	int sekunda;
	
	Time (int g, int m, int s)
	{
		godzina = g;
		minuta = m;
		sekunda = s;
	}
	
	void to_string() const
	{
		std::cout << std::setfill('0') << std::setw(2) << godzina << ":" << std::setfill('0') << std::setw(2) << minuta << ":" << std::setfill('0') << std::setw(2) << sekunda << std::endl;
	} 
	
	void next_hour()
	{
		godzina++;
		if (godzina > 23)
		{
			godzina = 0;
		}
	}

	void next_minute()
	{
		minuta++;
		if (minuta > 59)
		{
			minuta = 0;
			next_hour();
		}
	}
	
	void next_second()
	{
		sekunda++;
		if (sekunda > 59)
		{
			sekunda = 0;
			next_minute();
		}
	}
	
	Time_of_day time_of_day() const
	{
		Time_of_day td = Time_of_day::noc;
		
		if (godzina >= 0 && godzina < 6)
		{
			td = Time_of_day::noc;
		}
		
		if (godzina >= 6 && godzina < 12)
		{
			td = Time_of_day::rano;
		}
		
		if (godzina >= 12 && godzina < 18)
		{
			td = Time_of_day::dzien;
		}
		
		if (godzina >= 18 && godzina <= 23)
		{
			td = Time_of_day::wieczor;
		}
		
		return td;
	}
	std::string to_string(Time_of_day t)
	{
		std::string pora = "";
		if (t == Time_of_day::rano)
		{
			pora = "rano";	
		}
		
		if (t == Time_of_day::dzien)
		{
			pora = "dzień";	
		}
		
		if (t == Time_of_day::wieczor)
		{
			pora = "wieczór";	
		}
		
		if (t == Time_of_day::noc)
		{
			pora = "noc";	
		}
		return pora;
	}
	
	bool operator==(Time const& t)
	{
		if (this->godzina != t.godzina)
		{
			return false;
		}
		
		if (this->minuta != t.minuta)
		{
			return false;
		}
		
		if (this->sekunda != t.sekunda)
		{
			return false;
		}
		
		return true;
	}
	
	bool operator!=(Time const& t)
	{
		if (this->godzina == t.godzina)
		{
			if (this->minuta == t.minuta)
			{
				if (this->sekunda == t.sekunda)
				{
					return false;
				}
			}
		}
		
		return true;
	}
	
	bool operator>(Time const& t)
	{
		if (this->godzina < t.godzina)
		{
			return false;
		}
		
		if (this->minuta < t.minuta)
		{
			return false;
		}
		
		if (this->sekunda < t.sekunda)
		{
			return false;
		}
		
		return true;
	}
	
	bool operator<(Time const& t)
	{
		if (this->godzina > t.godzina)
		{
			return false;
		}
		
		if (this->minuta > t.minuta)
		{
			return false;
		}
		
		if (this->sekunda > t.sekunda)
		{
			return false;
		}
		
		return true;
	}
	
	Time operator+(Time const& t)
	{
		this->sekunda += t.sekunda;
		if (this->sekunda > 59)
		{
			this->minuta += (this->sekunda/60);
			this->sekunda = (this->sekunda%60);
		}
		this->minuta += t.minuta;
		if (this->minuta > 59)
		{
			this->godzina += (this->minuta/60);
			this->minuta = (this->minuta%60);
		}
		this->godzina += t.godzina;
		if (this->godzina > 23)
		{
			this->godzina = (this->godzina%24);
		}
		
		return *this;
	}
	
	Time operator-(Time const& t)
	{
		this->sekunda -= t.sekunda;
		if (this->sekunda < 0)
		{
			this->minuta -= ((-1*this->sekunda)/60)+1;
			this->sekunda = (60 + this->sekunda);
		}
		this->minuta -= t.minuta;
		if (this->minuta < 0)
		{
			this->godzina -= ((-1*this->minuta)/60)+1;
			this->minuta = (60 + this->minuta);
		}
		this->godzina -= t.godzina;
		if (this->godzina < 0)
		{
			this->godzina = (24 + this->godzina);
		}
		
		return *this;
	}
	
	auto count_seconds() const
	{
		return this->godzina * 3600 + this->minuta * 60 + this->sekunda;
	}
	
	auto count_minutes() const
	{
		return this->godzina * 60 + this->minuta;
	}
	
	auto time_to_midnight() const
	{
		return Time(0, 0, 0) - *this;
	}
};


