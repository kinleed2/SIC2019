//******************************************************************************
//
//
//      Vector
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "Vector.h"

//******************************************************************************
//
//      Vector2
//
//******************************************************************************

//--------------------------------
//  =
//--------------------------------
VECTOR2 &VECTOR2::operator=(const VECTOR2& v)
{
    x = v.x; y = v.y; return *this;
}

//--------------------------------
//  +=
//--------------------------------
VECTOR2 &VECTOR2::operator+=(const VECTOR2 &v)
{
    x += v.x;
    y += v.y;
    return *this;
}

//--------------------------------
//  -=
//--------------------------------
VECTOR2 &VECTOR2::operator-=(const VECTOR2 &v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

//--------------------------------
//  *=
//--------------------------------
VECTOR2 &VECTOR2::operator*=(float f)
{
    x *= f;
    y *= f;
    return *this;
}

//--------------------------------
//  /=
//--------------------------------
VECTOR2 &VECTOR2::operator/=(float f)
{
    x /= f;
    y /= f;
    return *this;
}

//--------------------------------
//  +（符号）
//--------------------------------
VECTOR2 VECTOR2::operator+() const
{
    return VECTOR2(x, y);
}

//--------------------------------
//  -（符号）
//--------------------------------
VECTOR2 VECTOR2::operator-() const
{
    return VECTOR2(-x, -y);
}

//--------------------------------
//  +（和）
//--------------------------------
VECTOR2 VECTOR2::operator+(const VECTOR2 &v) const
{
    return VECTOR2(x + v.x, y + v.y);
}

//--------------------------------
//  -（差）
//--------------------------------
VECTOR2 VECTOR2::operator-(const VECTOR2 &v) const
{
    return VECTOR2(x - v.x, y - v.y);
}

//--------------------------------
//  *
//--------------------------------
VECTOR2 VECTOR2::operator*(float f) const
{
    return VECTOR2(x * f, y * f);
}

//--------------------------------
//  *
//--------------------------------
VECTOR2 operator*(float f, const VECTOR2 &v)
{
    return VECTOR2(v.x * f, v.y * f);
}

//--------------------------------
//  /
//--------------------------------
VECTOR2 VECTOR2::operator/(float f) const
{
    return VECTOR2(x / f, y / f);
}

//--------------------------------
//  ==
//--------------------------------
bool VECTOR2::operator == (const VECTOR2& v) const
{
    return (x == v.x) && (y == v.y);
}

//--------------------------------
//  !=
//--------------------------------
bool VECTOR2::operator != (const VECTOR2& v) const
{
    return (x != v.x) || (y != v.y);
}

//--------------------------------
//  長さの2乗を取得
//--------------------------------
float vec2LengthSq(const VECTOR2& v)
{
    return v.x * v.x + v.y * v.y;
}

//--------------------------------
//  長さを取得
//--------------------------------
float vec2Length(const VECTOR2& v)
{
    return sqrtf(vec2LengthSq(v));
}

//--------------------------------
//  長さを1にする
//--------------------------------
VECTOR2* vec2Normalize(const VECTOR2& v, VECTOR2* out)
{
    *out = v;
    float d = vec2Length(v);
    if (d < FLT_EPSILON) return out;
    *out /= d;
    return out;
}

//******************************************************************************
//
//      Vector3
//
//******************************************************************************

//--------------------------------
//  =
//--------------------------------
VECTOR3 &VECTOR3::operator=(const VECTOR3& v)
{
    x = v.x;
    y = v.y;
    return *this;
}

//--------------------------------
//  +=
//--------------------------------
VECTOR3 &VECTOR3::operator+=(const VECTOR3 &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

//--------------------------------
//  -=
//--------------------------------
VECTOR3 &VECTOR3::operator-=(const VECTOR3 &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

//--------------------------------
//  *=
//--------------------------------
VECTOR3 &VECTOR3::operator*=(float f)
{
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

//--------------------------------
//  /=
//--------------------------------
VECTOR3 &VECTOR3::operator/=(float f)
{
    x /= f;
    y /= f;
    z /= f;
    return *this;
}

//--------------------------------
//  +（符号）
//--------------------------------
VECTOR3 VECTOR3::operator+() const
{
    return VECTOR3(x, y, z);
}

//--------------------------------
//  -（符号）
//--------------------------------
VECTOR3 VECTOR3::operator-() const
{
    return VECTOR3(-x, -y, -z);
}

//--------------------------------
//  +（和）
//--------------------------------
VECTOR3 VECTOR3::operator+(const VECTOR3 &v) const
{
    return VECTOR3(x + v.x, y + v.y, z + v.z);
}

//--------------------------------
//  -（差）
//--------------------------------
VECTOR3 VECTOR3::operator-(const VECTOR3 &v) const
{
    return VECTOR3(x - v.x, y - v.y, z - v.z);
}

//--------------------------------
//  *
//--------------------------------
VECTOR3 VECTOR3::operator*(float f) const
{
    return VECTOR3(x * f, y * f, z * f);
}

//--------------------------------
//  *
//--------------------------------
VECTOR3 operator*(float f, const VECTOR3 &v)
{
    return VECTOR3(v.x * f, v.y * f, v.z * f);
}

//--------------------------------
//  /
//--------------------------------
VECTOR3 VECTOR3::operator/(float f) const
{
    return VECTOR3(x / f, y / f, z / f);
}

//--------------------------------
//  ==
//--------------------------------
bool VECTOR3::operator == (const VECTOR3& v) const
{
    return (x == v.x) && (y == v.y) && (z == v.z);
}

//--------------------------------
//  !=
//--------------------------------
bool VECTOR3::operator != (const VECTOR3& v) const
{
    return (x != v.x) || (y != v.y) || (z != v.z);
}

//******************************************************************************
