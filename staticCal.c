//program to calcuate mean , median and mode for grouped data for saving time
#include<stdio.h>
#include<math.h>

int main()
{
 //request number of class
 int n;
 printf("Enter number of classes: ");
 scanf("%d",&n);


 //request class limits

 float class_lowerLimits[n+1];
 float class_upperLimits[n+1];

 float  class_lowerBoundries[n+1];
 float class_upperBoundries[n+1];

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
 

 //enterring class limits
 printf("Enter class Limits:(please note to add additional calls limit<sorry for the bug>) \n");
 for(int i=0 ; i<n+1 ;i++)
 {
    scanf("%f %f", &class_lowerLimits[i], &class_upperLimits[i]);
 }

//frequency
printf("Enter frequency: \n");
for(int i= 0 ;i<n ;i++)
{
    scanf("%d",&frequency[i]);
}

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
      class_lowerBoundries[i] =class_lowerLimits[i] - ((class_lowerLimits[i+1]-class_upperLimits[i])/2) ;
      class_upperBoundries[i] =class_upperLimits[i] + ((class_lowerLimits[i+1]-class_upperLimits[i])/2) ;
      
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
 





}