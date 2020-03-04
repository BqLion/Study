package src.main.java.com.bqlion.After.DataStruct.Sort;

/* *
 * Created by BqLion on 2019/11/10
 */
public class mergeSort {
    public static void merge(int[] arr,int low,int mid,int high,int[] temp){
        int i = 0;
        int j = low,k = mid +1;
        while(j <= mid && k <=high){      //把两个数组中小的装进temp数组
            if(arr[j] < arr[k]){
                temp[i++] = arr[j++];
            }
            else{
                temp[i++] = arr[k++];
            }
        }
        while(j <= mid){
            temp[i++] = arr[j++];
        }

        while(k <=high){
            temp[i++] = arr[k++];
        }

        for(int t = 0;t < i; t++){
            arr [low+t] = temp[t];
        }
    }

    public static void mergeSort(int[] arr, int low ,int high,int[] temp){
        if(low < high){
            int mid = (low+high)/2;
            mergeSort (arr,low,mid,temp);
            mergeSort(arr,mid+1,high,temp);
            merge(arr,low,mid,high,temp);
        }
    }

    public static void main(String[] args) {
        int[] arr = {11,33,4,55,6,7,44,22,335,55};
        int[] temp = new int[arr.length];
        mergeSort(arr,0,arr.length-1,temp);
        for(int i = 0;i < arr.length;i++){
            System.out.println(arr[i] + " ");
        }
    }
}
