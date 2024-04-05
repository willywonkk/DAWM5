#pragma once
#include <string>

namespace calculadoraKcal
{
    // Funci�n calcular las calor�as quemadas DEPORTE
    int fDeporte(std::string pSexo, int pA�os, int pKg, int pCm, int min, int pIntensidad, double met);

    // Funci�n calcular las calor�as quemadas PESAS
    int fPesas(int ejercicio, int tiempo);
}