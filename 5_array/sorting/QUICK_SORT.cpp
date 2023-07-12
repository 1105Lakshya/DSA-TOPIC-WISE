// element ko uski sahi jagga pahuchana haii or fir us se peeche sarre element us se chhotee hine chhiye or us se agge sarre element us se badee isko kehte hai partiiton karnnaa
// or fir recursivelly aisaa hi krnnaa haiii toh sort ho jaayegaaaa

// agar start greater than or   EQUAL to end ho toh matlab return karr jaooo 


//WHY QUICK SORT IS PREFFERED OVER MERGE SORT FOR SORTING ARRAYS  { VERY IMPORTANT }
//WHY MERGE SORT IS PREFFERED OVER QUICK SORT IN CASE OF LINKED LIST   {VERY IMPORTANT}

// quick sort average case time complexity nlogn   
//worst caxe time complexity squr(n)
//space O(n)


#include<iostream>
using namespace std;


//QUICK SORT ALGOO EXPLANATION
/*
STEP 1  --> WE PICK AN ELEMENT FROM THE ARRAY OR USKKO USKII SAHI JAGAAHHAA PE DAAL DETE HAIII  ISKO PARTITION KRNNA KEHTE HAII
[SAHI JAGAA MATLAB USKEE LEFT MEI  SARRE ELEMENT US SE CHHOTEE HONE CHHHIYYEE OR RIGHT MEI SARRE ELEMENT US SE BADDE HONNE CHHIYYYEEE]

STEP 2---> PARTITION WALLA FUNCTION HUMME EK INDEX DEDEGGAA AB APNNA KAAM LEFT PART KO SORT KRNNA OR RIGHT PART KO SORT KRNNNAA USS INDEX KEE KYKI WO TOH APNI D
//            SAHI JAGGA PR PAHUCH HI GAYYA NAA

STEP 3--> USKKE LIYYE HUMMM RECURSIVE CALL MARDEENGEE FOR         (START AND PARTITION -1)  && (PARTITION +1 AND END )     




//PARTITION KA LOGIIICCC
STEP1---> PEHLE EK ELEMENT SELECT KARLLOO ISKOO PIVOT ELEMENT BOLTTEE HUMME ISKO ISKI SAHI JAGGA PR PAHUCHHANA HAII
STEP2---> NEXT HUMM PIVOT SE JITNNE BHIII CHOOTE ELEMENT HAIII UNKOO COUNT KRLETTE HAIII  [SUPPOSE NO . OF ELEMENT LESS THAN PIVOT IS "COUNT "]
STEP3---> PIVOT KO USKKI RIGHT JAGGA PR PLACE KR DETEE HAII BY REPLACING IT WITH THE ELEMENT THAT IS AT THE POSITTION  ====>[ START +COUNT ]
STEP4---> AB APNEE KO LEFT OR RIGHT PART KO ISS TARAAH SE KRNNA HAII KI LEFT MEI SARRE ELEMENT PIVOT SE CHHOOTE HOO OR RIGHT MEI SARRE US SE BADDEE
USKKE LIYYE HUMM POINTER BITHHA DENGGE LEFT PART KE STARTING MEI  OR RIGHT PART KE END  MEI  OR ITERATE KRRENGEE AGAR LEFT PART MEI KOI PIVOT SE BADDA HAII TOH ROOKK LENGGEE
FIR RIGHT PART MEI ITERATE KREENGEE  AGAR  LOI ELEMENT CHHOTA HOGGAA TOH ROOOK LENGGE DONOT KO SWAP MARRDENGEE FIR LEFT WALLE POINTER KO AGGE BHADDDDA DENGGE
OR RIGHT WALLE POINTER KO GHATTAA DENGGE  STOP KR JAAYENGEEE WHEN LEFT POINTER AND RIGHT POINTER DONO EK JAGGA AA JAYYE                                                                  
*/


int partition(int arr[],int s,int e){
int pivot=arr[s];
int count=0;
for(int i=s+1;i<=e;i++){
if(arr[i]<=pivot)
count++;
}
//place pivot at right position 
int pivotIndex=s+count;
swap(arr[s],arr[pivotIndex]);

//left and right wala part smbhal lete hai
int i=s,j=e;
while(i<pivotIndex && j>pivotIndex){
while(arr[i]<pivot){
    i++;
}
while(arr[j]>pivot){
    j--;
}
if(i<pivotIndex  && j>pivotIndex){
    swap(arr[i++],arr[j--]);
}
}
return pivotIndex;
}




void quickSort(int arr[],int s,int e){
    //base case
    if(s>=e){
        return;
    }
    int pivot=partition(arr,s,e);
    // left walla sort
    quickSort(arr,s,pivot-1);
    // Right walla sort 
    quickSort(arr,pivot+1,e);
}




int main(){
    int arr[5]={2,4,1,6,9};
    int n=5;
    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    return 0;
} 