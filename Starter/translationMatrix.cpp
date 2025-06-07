#include "matrix4x4.h"

TranslationMatrix::TranslationMatrix(double tx, double ty, double tz) : Matrix4x4(1.0f, 0.0f, 0.0f, tx, 0.0f, 1.0f, 0.0f, ty, 0.0f, 0.0f, 1.0f, tz, 0.0f, 0.0f, 0.0f, 1.0f) {}
