/*
babbaar bhiiyya viedoo and code studio question

class NStack
{
    int *arr;
    int *top;          //array to store top position of each stack
    int *next;        // array to store next free space if no element is present else it stores top se neeche walla element of the stack
    
    int n, s;
     
    int freespot;
    
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        //top initialise
        for(int i=0; i<n; i++) {
            top[i] = -1;
        }
        
        //next initialise
        for(int i=0; i<s; i++) {
            next[i] = i+1;
        }
        //update last index value to -1
        next[s-1] = -1;
        
        //initialise freespot
        freespot = 0;
        
    }

     // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
	//check for overflow
		if(freespot==-1){
			return false;
		}
		
	//find index
		int index=freespot;

	//insert element into an arrray 
		arr[index]=x;   // next top ke neeche walla store kttii haii agar index pe freespot na hooo takki pop krne ke kaam ayye
		
	//update free spot
		freespot=next[index];
	

	//update next
		next[index]=top[m-1];
	//update top
		top[m-1]=index;
		return true;
	}

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)   //pop mei bas exact ulta krna hai push kaa
    {
//check underflow condition
		if(top[m-1]==-1){
			return -1;
		}
// pop krnee walla index jo hogga wo top wall hi toh hogga	
		int index=top[m-1];
// pop krne ke liyee maine kya kiya ki top ko ek position nechhe shift krrrdiyyaa jo ki mainee next walli array mei save krrii thiii		
		top[m-1]=next[index];
//jahha se pop huaa haii wahh pr free spot daal diyyaa
		next[index]=freespot;
//ab jahh se pop huaa haii wahha free space banngyii 	
		freespot=index;
// return krdiyya element us index pe	
		
		return arr[index];
		
	}
};


*/