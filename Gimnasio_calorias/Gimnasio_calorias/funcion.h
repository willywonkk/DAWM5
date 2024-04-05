#pragma once
#include <string>

namespace calculadoraKcal
{
    // Función calcular las calorías quemadas DEPORTE
    int fDeporte(std::string pSexo, int pAños, int pKg, int pCm, int min, int pIntensidad, double met);

    // Función calcular las calorías quemadas PESAS
    int fPesas(int ejercicio, int tiempo);
}