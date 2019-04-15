
//剑指offer
//请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
class Solution {
public:
    void replaceSpace(char *str,int length) {
        int p=0;
        int i;
        for(i=0;str[i]!='\0';++i){
            if(str[i]==' '){
                p++;
            }
        }
        int sizeofelement_a=i;
        int newsize_b=i+2*p;
        if (newsize_b>length)
            return;
        //char str_b[sizeofelement_a];
        str[newsize_b]='\0';
        int index_a=sizeofelement_a-1;
        int index_b=newsize_b-1;
        while(index_a>=0&&index_b>index_a){
            if(str[index_a]==' '){
                str[index_b--]='0';
                str[index_b--]='2';
                str[index_b--]='%';

            }
            else{
                str[index_b--]=str[index_a];
            }
            index_a--;
        }
        

    }
};
//剑指offer在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row=(int)array.size();
        int col=(int)array[0].size();
        if(row==0||col==0)
            return false;
        if(array[row-1][col-1]<target||array[0][0]>target)
            return false;
        int p_col=col-1;
        int p_row=0;
        while(p_col>=0&&p_row<=row-1){
            if(array[p_row][p_col]>target){
                p_col--;
            }
            else if (array[p_row][p_col]<target){
                p_row++;
            }
            
            else
                return 1;
            
        }
        return false;
        
    }
};



