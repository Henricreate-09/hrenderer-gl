#pragma once


struct Color {
    // These can hold RGBA(0-255) values and normalized(0-1) values
    float r,g,b,a;

    Color();
    Color(const float &r, const float &g, const float &b);
    Color(const float &r, const float &g, const float &b, const float &a);

    Color FromNormalized(const float &nR, const float &nG, const float &nB);
    Color FromNormalized(const float &nR, const float &nG, const float &nB, const float &nA);


    static float ValueToNormalized(const float &rgbValue);
    static float ValueToRGB(const float &normalizedValue);
};