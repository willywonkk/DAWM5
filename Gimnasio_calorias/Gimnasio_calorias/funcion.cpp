#include "funcion.h"
#include <string>

namespace calculadoraKcal
{
    // Implementación DEPORTE
    int fDeporte(std::string pSexo, int pAños, int pKg, int pCm, int min, int pIntensidad, double met) {
        int MB;
        if (pSexo == "H") {
            MB = 88.362 + (13.397 * pKg) + (4.799 * pCm) - (5.677 * pAños);
        }
        else if (pSexo == "M") {
            MB = 447.593 + (9.247 * pKg) + (3.098 * pCm) - (4.330 * pAños);
        }
        double totalmet = (met * pKg) * min;
        double totalKcal = ((MB * pIntensidad) / 1440 + totalmet) / min;
        return totalKcal;
    }

    // Implementación PESAS
    int fPesas(int ejercicio, int tiempo) {

        int Kcalquemadas = 0;

        if (ejercicio == 1 || ejercicio == 2 || ejercicio == 4 || ejercicio == 5) {
            Kcalquemadas = (tiempo / 15) * 100;
        }
        else if (ejercicio == 3) {
            Kcalquemadas = (tiempo / 15) * 150;
        }
        return Kcalquemadas;
    }
}
