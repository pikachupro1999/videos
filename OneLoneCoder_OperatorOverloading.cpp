/*
	Operator Overloading
	"Yes, ok, the video had a bug..." - javidx9

	License (OLC-3)
	~~~~~~~~~~~~~~~

	Copyright 2018-2019 OneLoneCoder.com

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions
	are met:

	1. Redistributions or derivations of source code must retain the above
	copyright notice, this list of conditions and the following disclaimer.

	2. Redistributions or derivative works in binary form must reproduce
	the above copyright notice. This list of conditions and the following
	disclaimer must be reproduced in the documentation and/or other
	materials provided with the distribution.

	3. Neither the name of the copyright holder nor the names of its
	contributors may be used to endorse or promote products derived
	from this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
	A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
	HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
	LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
	DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
	THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

	Relevant Video: https://youtu.be/4FyeBUPrwKY

	Links
	~~~~~
	YouTube:	https://www.youtube.com/javidx9
	Discord:	https://discord.gg/WhwHUMV
	Twitter:	https://www.twitter.com/javidx9
	Twitch:		https://www.twitch.tv/javidx9
	GitHub:		https://www.github.com/onelonecoder
	Patreon:	https://www.patreon.com/javidx9
	Homepage:	https://www.onelonecoder.com

	Author
	~~~~~~
	David Barr, aka javidx9, ©OneLoneCoder 2019
*/


#include <iostream>

// -== Operator Overloading ==-
template <class T>
struct v2d_generic
{
	T x = 0;
	T y = 0;

	v2d_generic() : x(0), y(0)                        {                                                      }
	v2d_generic(T _x, T _y) : x(_x), y(_y)            {                                                      }
	v2d_generic(const v2d_generic& v) : x(v.x), y(v.y){                                                      }
	T mag()	                                          {return sqrt(x * x + y * y);	                         }
	v2d_generic  norm()                               {T r = 1 / mag(); return v2d_generic(x*r, y*r);	     }
	v2d_generic  perp()                               {return v2d_generic(-y, x);                            }
	T dot(const v2d_generic& rhs)                     {return this->x * rhs.x + this->y * rhs.y;             }
	T cross(const v2d_generic& rhs)                   {return this->x * rhs.y - this->y * rhs.x;             }
	v2d_generic  operator +  (const v2d_generic& rhs) {return v2d_generic(this->x + rhs.x, this->y + rhs.y); }
	v2d_generic  operator -  (const v2d_generic& rhs) {return v2d_generic(this->x - rhs.x, this->y - rhs.y); }
	v2d_generic  operator *  (const T& rhs)           {return v2d_generic(this->x * rhs, this->y * rhs);	 }
	v2d_generic  operator /  (const T& rhs)           {return v2d_generic(this->x / rhs, this->y / rhs);	 }
	v2d_generic& operator += (const v2d_generic& rhs) {this->x += rhs.x; this->y += rhs.y; return *this;     }
	v2d_generic& operator -= (const v2d_generic& rhs) {this->x -= rhs.x; this->y -= rhs.y; return *this;     }
	v2d_generic& operator *= (const T& rhs)           {this->x *= rhs; this->y *= rhs; return *this;	     }
	v2d_generic& operator /= (const T& rhs)           {this->x /= rhs; this->y /= rhs; return *this;	     }
	T& operator [] (std::size_t i)	                  {return *((T*)this + i);	   /* <-- D'oh :( */         }
};

typedef v2d_generic<float> vf2d;
typedef v2d_generic<double> vd2d;

int main()
{
	vf2d a = { 1.0f, 2.5f };
	vf2d b = { 2.0f, 3.5f };
	vf2d c = { 3.0f, 4.5f };

	a[1] = 8.0f;
	float f = a[0];
	a *= 89.4f;
	a += b - c * 7.0f + a / (b + c * 2.0f).mag();

	return 0;
}

