int main(){
    void MergeList(List &LA,List LB)
    {//将所有在线性表LB中但不在LA中的数据元素插入到LA中
        m=ListLength(LA); n=ListLength(LB);           //求线性表的长度
        for(i=1;i<=n;i++)
        {
            GetElem(LB,i,e);                           //取LB中第i个数据元素赋给e
            if(!LocateElem(LA,e))                      //LA中不存在和e相同的数据元素
                ListInsert(LA,++m,e);                   //将e插在LA的最后
        }
    }
}