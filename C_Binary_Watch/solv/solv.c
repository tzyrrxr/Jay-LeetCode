char ** readBinaryWatch(int turnedOn, int* returnSize){
     char** final_arr = (char**)malloc(190*sizeof(char*));
    int count =0;
    for (int k=0;k<720;k++){ // 720 min half a day
        unsigned char h = k/60; // unsigned char from 0 to 255
        unsigned char m = k%60;
        int count_bit = 0;
        while(h>0){
            if (h%2==1){
                count_bit++;
            }
            h>>=1;
        }
        while (m>0){
            if (m%2==1){
                count_bit++;
            }
            m>>=1;
        }
        if (count_bit==turnedOn){
            final_arr[count]= (char*)malloc(8*sizeof(char));
            snprintf(final_arr[count],8,"%d:%02d",k/60,k%60);
            count++;
        }  
    }
    *returnSize = count;
 return final_arr;
}
