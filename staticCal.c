//program to calcuate mean , median and mode ,variance standard deviation ,ith percentiles ,Quartiles for grouped data for saving time
#include<stdio.h>
#include<math.h>

int main()
{
 //request number of class
 int n;
 printf("Enter number of classes: ");
 scanf("%d",&n);


 //request class limits

 float class_lowerLimits[n];
 float class_upperLimits[n];

 float  class_lowerBoundries[n];
 float class_upperBoundries[n];

 int frequency[n];
 float classMark[n];
 float fiXmi[n];
 float mean ;
 float sumfiXmi = 0;
 float sumfrequency =0;

 int cumulativeFrequency[n];

 float lowerClassBoundry_medianclass;
 float upperClassBoundry_medianclass;
 float median;

 float modalclassLowerboundry;
 float mode;
 float frequencyofModalclass;
 float frequencyoftheclassBeforeModelclass;
 float frequencyoftheclassAftereModelclass;

 float fiXmi2[n];
 float sumfiXmi2 = 0;

 float cumulative_percentile[n];
 float percentile;

 //float Q1 ,Q2 ,Q3;
 float percentile25;
 float percentile50;
 float percentile75;
 

 //enterring class limits
 printf("Enter class Limits: \n");
 for(int i=0 ; i<n ;i++)
 {
    scanf("%f %f", &class_lowerLimits[i], &class_upperLimits[i]);
 }

//frequency
printf("Enter frequency: \n");
for(int i= 0 ;i<n ;i++)
{
    scanf("%d",&frequency[i]);
}
//asking from user wether it is population or sample
int choice;
printf("Enter 1 for sample data \n");
printf("Enter 2 for Population data \n");
scanf("%d",&choice);

 //classmark
 for(int i=0 ;i<n;i++)
 {
   classMark[i]=(class_lowerLimits[i]+class_upperLimits[i])/2;
 }
 //fiXmi
 for(int i=0 ;i<n;i++)
 {
   fiXmi[i]= frequency[i] * classMark[i];
 }

 //formula for mean<toatal of fiXmi>
for(int i=0; i<n ;i++)
{
   sumfiXmi+= fiXmi[i];
}
for(int i=0; i<n ;i++) //toatal frequency
{
   sumfrequency += frequency[i]; 
}

//cumulative_frequency
int i;
for(i=0 ; i<n ;i++)
{
    if(i==0)
        cumulativeFrequency[i]=frequency[i];
    else
        cumulativeFrequency[i]=frequency[i]+cumulativeFrequency[i-1];
}



 /////////////printing section///////////////////////////////////////////////////////////////////////////////////////


 //create classboundries ,frequency ,classMark
 printf("\n\n");
 
 printf("******************************************************************************************************\n");
 printf("Class limits\t       class boundries  \t frequency  \tclassMark   \t cumulative_F\n");
 for(int i=0 ; i<n ;i++)
 {
      if(i==0)
      {
        class_lowerBoundries[0]= class_lowerLimits[0]+(class_lowerLimits[1] -class_upperLimits[0])/2;
        class_upperBoundries[0]= class_upperLimits[0]+(class_lowerLimits[1] -class_upperLimits[0])/2;     
      }
      else if(i==n)
      { 
        class_lowerBoundries[n]= class_lowerLimits[n]-(class_lowerLimits[n] -class_upperLimits[n-1])/2;
        class_upperBoundries[n]= class_upperLimits[n]+(class_lowerLimits[n] -class_upperLimits[n-1])/2;
      }
      else
      {
        class_lowerBoundries[i] =class_lowerLimits[i] - ((class_lowerLimits[i+1]-class_upperLimits[i])/2) ;
        class_upperBoundries[i] =class_upperLimits[i] + ((class_lowerLimits[i+1]-class_upperLimits[i])/2) ;
      }
      
      printf("%.2f   %.2f   \t%.2f   %.2f     \t %d   \t             %.2f         %d\n",class_lowerLimits[i], class_upperLimits[i] ,class_lowerBoundries[i], class_upperBoundries[i],frequency[i],classMark[i],cumulativeFrequency[i]);
 }
 printf("******************************************************************************************************\n");
 printf("\n\n");
 //mean
 mean = sumfiXmi/sumfrequency;
 printf("Mean is %.2f \n" ,mean);

//median
float middlepoint = sumfrequency/2;
for(i=0 ; i<n ;i++)
{
 if(middlepoint<cumulativeFrequency[i] && middlepoint>cumulativeFrequency[i-1])
 {
    lowerClassBoundry_medianclass = class_lowerBoundries[i];
    upperClassBoundry_medianclass = class_upperBoundries[i];
    median = lowerClassBoundry_medianclass +((sumfrequency/2-cumulativeFrequency[i-1])/frequency[i])*(class_upperBoundries[i]-class_lowerBoundries[i]);
    printf("Median: %.2f \n",median); 
 }
}

//mode
int highestFrquency=0;
for(i=0 ;i<n ;i++)
{ 
   if(frequency[i]>highestFrquency)
     {
       highestFrquency=frequency[i];
       modalclassLowerboundry = class_lowerBoundries[i];
       frequencyofModalclass = frequency[i];
       frequencyoftheclassBeforeModelclass =frequency[i-1];
       frequencyoftheclassAftereModelclass = frequency[i+1];
     }   
}

float classSize = upperClassBoundry_medianclass - lowerClassBoundry_medianclass;

float delta1 =frequencyofModalclass-frequencyoftheclassBeforeModelclass;
float delta2 =frequencyofModalclass-frequencyoftheclassAftereModelclass;
mode = modalclassLowerboundry + (delta1/(delta1+delta2))*classSize;

printf("Mode %.2f \n",mode);



//variance & standard deviation
printf("\n\n");
switch(choice)
{
   case 1:
   for(i=0 ; i<n ;i++)
   {
      fiXmi2[i] = frequency[i]*classMark[i]*classMark[i];
      sumfiXmi2+= fiXmi2[i];
   }
   
   //printf("%.2f \n" ,(sumfrequency*(sumfrequency-1)));

   float variance =((sumfrequency*sumfiXmi2) -(sumfiXmi*sumfiXmi))/(sumfrequency*(sumfrequency-1)) ;
   printf("Sampel variance is %.2f \n",variance);
   printf("Sample Standard deviation is %.2f \n", sqrt(variance));
   break;

   case 2:
   variance =((sumfrequency*sumfiXmi2) -(sumfiXmi*sumfiXmi))/(sumfrequency*sumfrequency) ;
   printf("Population variance is %.2f \n",variance);
   printf("Population Standard deviation is %.2f \n", sqrt(variance));
   break;
   

   default:
   printf("wrong choice \n");
   break;
}

//percentiles for group data
printf("\n\n");
int Ipercentile;
printf("Enter the percentile youwant to find:");
scanf("%d" ,&Ipercentile);

float lowerclassboundry_percentileclass;
int frequency_percentileclass;
int classbefore_percentileclass;

//cumulative percentile
for(i=0 ;i<n ;i++)
{
  cumulative_percentile[i] = (cumulativeFrequency[i]/sumfrequency)*100;
}

for(i=0 ;i<n ;i++)
{
  if(Ipercentile<=cumulative_percentile[i] && Ipercentile>cumulative_percentile[i-1])
  {
    lowerclassboundry_percentileclass = class_lowerBoundries[i];
    frequency_percentileclass = frequency[i];
    classbefore_percentileclass= cumulativeFrequency[i-1];
  }
}


percentile = lowerclassboundry_percentileclass +(((sumfrequency/100)*Ipercentile -classbefore_percentileclass)/frequency_percentileclass)*classSize ;

printf("%d th percentile is %.2f \n" ,Ipercentile ,percentile);


printf("\n\n");
//Quartiles
//Q1
int percentile_25 = 25;
float lowerclassboundry_percentileclass_25;
int frequency_percentileclass_25;
int classbefore_percentileclass_25;

for(i=0 ;i<n ;i++)
{
  if(percentile_25<=cumulative_percentile[i] && percentile_25>cumulative_percentile[i-1])
  {
    lowerclassboundry_percentileclass_25 = class_lowerBoundries[i];
    frequency_percentileclass_25 = frequency[i];
    classbefore_percentileclass_25= cumulativeFrequency[i-1];
  }
}

percentile25 = lowerclassboundry_percentileclass_25 +(((sumfrequency/100)*percentile_25 -classbefore_percentileclass_25)/frequency_percentileclass_25)*classSize ;
printf("Q1 is %.2f \n",percentile25);


//Q2
int percentile_50 = 50;
float lowerclassboundry_percentileclass_50;
int frequency_percentileclass_50;
int classbefore_percentileclass_50;

for(i=0 ;i<n ;i++)
{
  if(percentile_50<=cumulative_percentile[i] && percentile_50>cumulative_percentile[i-1])
  {
    lowerclassboundry_percentileclass_50 = class_lowerBoundries[i];
    frequency_percentileclass_50 = frequency[i];
    classbefore_percentileclass_50= cumulativeFrequency[i-1];
  }
}

percentile50 = lowerclassboundry_percentileclass_50 +(((sumfrequency/100)*percentile_50 -classbefore_percentileclass_50)/frequency_percentileclass_50)*classSize ;
printf("Q2 is %.2f \n",percentile50);

//Q3
int percentile_75 = 75;
float lowerclassboundry_percentileclass_75;
int frequency_percentileclass_75;
int classbefore_percentileclass_75;

for(i=0 ;i<n ;i++)
{
  if(percentile_75<=cumulative_percentile[i] && percentile_75>cumulative_percentile[i-1])
  {
    lowerclassboundry_percentileclass_75 = class_lowerBoundries[i];
    frequency_percentileclass_75 = frequency[i];
    classbefore_percentileclass_75= cumulativeFrequency[i-1];
  }
}

percentile75 = lowerclassboundry_percentileclass_75 +(((sumfrequency/100)*percentile_75 -classbefore_percentileclass_75)/frequency_percentileclass_75)*classSize ;
printf("Q3 is %.2f \n",percentile75);



}