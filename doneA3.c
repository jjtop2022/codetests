/****************************************************************/

// Function 1: Reading from file and copy to last two parameters
void readFromFile (char fName [30], int country [COUNTRIES][MEDALCAT], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]){

    printf ("Filename: %s\n", fName);
    FILE *fp;
    fp = fopen(fName,"r");
    char country1[MAX_LENGTH_CNAME]="";
    int gmedal=0;
    int smedal=0;
    int bmedal=0;
    if (fp == NULL){
        printf ("File could not be opened!\n");
    }else{
        //open the file and add to arrays
        int ccount=0; //country count

        while(!feof(fp)){
            fscanf(fp, "%s%d%d%d", country1,&gmedal,&smedal,&bmedal);

            //1. Fill the arrays from the parameters - medal count
            country[ccount][0] = gmedal;
            country[ccount][1] = smedal;
            country[ccount][2] = bmedal;
            //2. Now fill the country names
            strcpy(countryNames[ccount], country1);
            printf ("Country: %s, counts: %d %d %d\n", countryNames[ccount],country[ccount][0],country[ccount][1],country[ccount][2]);
            ccount++;

        }
        fclose(fp);
    }

}

//Function 2: Finds total medals per country, stores in totalAllCountries array
void findTotalPerCountry (int country [COUNTRIES] [MEDALCAT],
                int totalAllCountries [COUNTRIES]) {
    //Assume from Function 1 - first parameter is populated
    int i, j;
    for (i=0;i<COUNTRIES;i++) {
        int total=0;  //total medal count for each country
        for (j=0;j<MEDALCAT;j++){
              total += country[i][j];
              //printf ("Total each medal: %d %d %d %d\n", total, country[i][j], i,j);
        }
        totalAllCountries[i] = total;
        printf ("Country index: %d Total medal count: %d\n",i,totalAllCountries[i]);
    }
    printf ("\n");

}

//Function 3: Finds total medals in each category, stores in totalAllMedals array
int findTotalPerMedal (int country [COUNTRIES][MEDALCAT],
                int totalAllMedals [MEDALCAT], int * whichMedal){
        int i,j;
        for (j=0;j<MEDALCAT;j++){
        int medalcount=0;
            for (i=0;i<COUNTRIES;i++){
                medalcount += country[i][j];

            }
            totalAllMedals[j] = medalcount;
            printf ("%d %d\n", j, totalAllMedals[j]);
        }
        int max=totalAllMedals[0];
        int pvalue=0; //contains greatest value medal index

        for (j=1;j<MEDALCAT;j++){
            if (totalAllMedals[j] > max){
                pvalue = j;
                max = totalAllMedals[j];
            }
        }
        printf ("PVALUE: %d\n", pvalue);
        *whichMedal = pvalue;
        return pvalue;

}

//Function for number 4 - to printout number of stars
void printstars(int numstars, int mod){
   int i;
   for (i=0;i<numstars;i++){
       printf("*");
   }
   if (mod == 1){
       printf("*");
   }
}

//Function 4: printout total medals for each country
void hHistogram (char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalMedals[COUNTRIES]){
       int i;
       for (i=0;i<COUNTRIES;i++){
            printf ("%-10s: ",countryNames[i]);
            int numstar = totalMedals[i]/2;
            int modnum = totalMedals[i] % 2; //if result one, add a star
            printstars(numstar,modnum);
            printf (" (%d)\n",totalMedals[i]);

       }

}

//Function 5: search by country - returns total medals won by country
int searchCountry (char countryName [MAX_LENGTH_CNAME], char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalAllCountries [COUNTRIES]){
    int result = -1;
    int i;
    for (i=0;i<COUNTRIES;i++){
         if (strcmp(countryName,countryNames[i]) == 0){
            return totalAllCountries[i];
         }
    }
    return result;
}

//Function 6:  Rank top 3 based on Total medals
void rankTopThreeByTotal (int totalMedals[COUNTRIES], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]){
     int i;
     for (i=0;i<3;i++){
         printf ("%s (%d)\n", countryNames[i],totalMedals[i]);
     }
     printf ("\n");

}

//Function 7: Rank top 3 by Gold medal, assume the countries are sorted
// inside the file already by total medals.
void rankTopThreeByMedal (int country [COUNTRIES] [MEDALCAT], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]){
     int i;
     printf ("Rank top three Based on Gold medals\n");
     for (i=0;i<3;i++){
          printf("%s (%d)\n",countryNames[i], country[i][0]);

     }

}


//Function 8: check no medal
int checkNomedalcount(int country[COUNTRIES][MEDALCAT],int indexOfCountries[COUNTRIES],int medal){
    int noMedcount=0;
    int i;
    for (i=0;i<COUNTRIES;i++){
        if (country[i][medal] == 0){
                noMedcount++;
                indexOfCountries[i] = 1;
        }
    }
    return noMedcount;
}
//Function 8:
int findAllWithNoXMedals (int country [COUNTRIES] [MEDALCAT],
                          int indexMedal, int indexOfCountries [COUNTRIES]){
    int totalcountryNoMed=0; //returns countries without medal
    //1. Gold, 2. Silver, 3. Bronze
    if (indexMedal == 1){  //Gold
           //check country with no medals
            totalcountryNoMed = checkNomedalcount(country, indexOfCountries,0);


    }else if (indexMedal == 2){ //Silver
            totalcountryNoMed = checkNomedalcount(country, indexOfCountries,1);

    }else if (indexMedal == 3){  //Bronze
           totalcountryNoMed = checkNomedalcount(country,indexOfCountries, 2);

    }
    return totalcountryNoMed;

}


//Function 9 - check countries with ONLY medal specified
int checkOnlyMedal(int country[COUNTRIES][MEDALCAT], int medal, int only1, int only2){
    int onlycount=0;
    int i;
    for (i=0;i<COUNTRIES;i++){
        //if country has required medal > 0
        if (country[i][medal] > 0){
            if (country[i][only1] == 0){ //check other medal is 0
               if(country[i][only2] == 0){ //check 3rd medal is 0
                   onlycount++;
               }
            }

        }
    }
    return onlycount;
}


//Function 9: Returns with only that medal in that category
int findAllWithOnlyXMedals (int country [COUNTRIES][MEDALCAT],
                    int indexMedal, int indexOfCountries [COUNTRIES]){
    int onlycount=0;
    if (indexMedal == 1){ //gold
       onlycount = checkOnlyMedal(country,0,1,2);

    }else if (indexMedal == 2){ //silver
       onlycount = checkOnlyMedal(country,1,0,2);

    }else if (indexMedal == 3){ //bronze
       onlycount = checkOnlyMedal(country,2,0,1);

    }
    return onlycount;

}




//Function 10: Return the country name with MAX length
int findCountryIndexWithMinOrMaxLength (int minOrMax, char countryNames [COUNTRIES][MAX_LENGTH_CNAME]){
       //We will look for the MAX length
       int i;
       int max=0; int cindex=0; int min=9999;

       if (minOrMax == 2){ // max
           for (i=0;i<COUNTRIES;i++){
                int tempmax = strlen(countryNames[i]);
                if (tempmax > max){
                      max = tempmax;
                      cindex = i;
                }
           }

       }else if (minOrMax == 1) { // minimun
            for (i=0;i<COUNTRIES;i++){
                 int tempmin = strlen(countryNames[i]);
                 if (tempmin < min){
                     min = tempmin;
                     cindex = i;
                 }
            }
       }
       return cindex;

}

