class Solution{
  public:
    
int tour(petrolPump p[],int n)
    {
       int start = 0;
       int rear = 1;
       
       int curr_petrol = p[0].petrol - p[0].distance;
       
       while(curr_petrol < 0 || start != rear)
       {
           while(curr_petrol < 0 && start != rear)
           {
               curr_petrol -= (p[start].petrol - p[start].distance);
               start = (start + 1)%n;
               if(start == 0)
               return -1;
           }
           
           curr_petrol += (p[rear].petrol - p[rear].distance);
       
       rear = (rear + 1)%n;
       }
       
       return start;
    }
};

