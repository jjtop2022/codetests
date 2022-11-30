#include <stdio.h>
#include <string.h>

#define COUNTRIES 15
#define MEDALCAT 3
#define MAX_LENGTH_CNAME 100

void readFromFile (char fName [30], int country [COUNTRIES][MEDALCAT], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]);

void findTotalPerCountry (int country [COUNTRIES] [MEDALCAT],
                int totalAllCountries [COUNTRIES]);

int findTotalPerMedal (int country [COUNTRIES][MEDALCAT],
                int totalAllMedals [MEDALCAT], int * whichMedal);

void hHistogram (char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalMedals[COUNTRIES]);

int searchCountry (char countryName [MAX_LENGTH_CNAME], char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalAllCountries [COUNTRIES]);

void rankTopThreeByTotal (int totalMedals[COUNTRIES], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]);

void rankTopThreeByMedal (int country [COUNTRIES] [MEDALCAT], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]);

int findAllWithNoXMedals (int country [COUNTRIES] [MEDALCAT],
						  int indexMedal, int indexOfCountries [COUNTRIES]);

int findAllWithOnlyXMedals (int country [COUNTRIES][MEDALCAT],
						  int indexMedal, int indexOfCountries [COUNTRIES]);

int findCountryIndexWithMinOrMaxLength (int minOrMax, char countryNames [COUNTRIES][MAX_LENGTH_CNAME]);



