#include "Color.hpp"


Color::Color() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = 0;
}

Color::Color(const float &r, const float &g, const float &b) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = 255;
}

Color::Color(const float &r, const float &g, const float &b, const float &a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

Color Color::FromNormalized(const float &nR, const float &nG, const float &nB) {
    return Color(nR*255, nG*255, nB*255);
}

Color Color::FromNormalized(const float &nR, const float &nG, const float &nB, const float &nA) {
    return Color(nR*255, nG*255, nB*255, nA*255);
}

float Color::ValueToNormalized(const float &rgbValue)
{
    return rgbValue/255;
}

float Color::ValueToRGB(const float &normalizedValue)
{
    return normalizedValue*255;
}
