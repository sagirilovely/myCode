#include "String.h"

//打印字符串
Status DisplayString(String s) {
    if (s.len > 0) {
        for (int i = 0; i < s.len; i++) {
            cout << s.data[i];
        }
        cout << endl;
        return OK;
    } else if (s.len == 0) {
        cout << "" << endl;
        return OK;
    } else {
        return ERROR;
    }
}

//将一个字符数组转成String
Status StrAssign(String &s, const char c[], int length) {
    if (length > MAXSIZE) {
        //字符数组太长了,无法将一个字符数组存进去
        return ERROR;
    } else {
        s.len = 0;
        for (int i = 0; i < length; i++) {
            s.data[i] = c[i];
            s.len++;
        }
        s.data[s.len] = '\0';
        return OK;
    }
}

//销毁字符串
Status DestroyString(String &s) {
    s.data[0] = '\0';
    s.len = 0;
    return OK;
}

//将串t复制给s
Status CopyString(String &s, String t) {
    s.len = 0;
    for (int i = 0; i < t.len; i++) {
        s.data[i] = t.data[i];
        s.len++;
    }
    s.data[s.len] = '\0';
    return OK;
}

//返回字符串的长度
Status GetLenString(String s) {
    return s.len;
}

//判断两个串是否相等
Status IsEqualString(String s, String t) {
    if(s.len!=t.len){
        return FALSE;
    }
    for (int i = 0; i < s.len; i++) {
        if (s.data[i] != t.data[i]) {
            return FALSE;
        }
    }
    return TRUE;
}

//连接两个串,并返回新串,s在前,t在后
Status ConcatString(String s, String t, String &newString) {
    newString.len = 0;
    for (int i = 0; i < s.len; i++) {//将s放入新串
        newString.data[i] = s.data[i];
        newString.len++;
    }
    for (int i = 0; i < t.len; i++) {//将t放入新串
        newString.data[i + s.len] = t.data[i];
        newString.len++;
    }
    newString.data[newString.len] = '\0';
    return OK;
}

//返回串s中,第start个位置到第end个位置之间的串(左闭右开)
Status SubString(String s, int start, int end, String &n) {
    if (end > s.len) {
        return ERROR;
    } else {
        int j = 0;
        for (int i = start - 1; i < end - 1; i++) {
            n.data[j] = s.data[i];
            j++;
        }
        n.len = j;
        return OK;
    }
}

//返回字串t在主串s中的位置,朴素算法
Status GetIndexString(String s, String t) {
    for (int i = 0; i < (s.len - t.len + 1); i++) {
        for (int j = 0; j < t.len; j++) {
            if (s.data[i + j] == t.data[j] && j == (t.len - 1)) {
                return i + 1;
            }
            if (s.data[i + j] != t.data[j]) {
                break;
            }
        }
    }
    return ERROR;
}

//将子串t插入到主串s的start位置
Status InsertString(String &s, String t, int start) {
    if ((s.len + t.len) > MAXSIZE) {
        return ERROR;
    }
    if (start > s.len) {
        return ERROR;
    }
    s.len = s.len + t.len;
    //遍历s 下标[start-1 ,s.len)拿出来存进临时变量里
    //连接s + t--> 连接后的s
    //连接s + 临时变量-->最终的s
    String s_son;
    int j = 0;
    for (int i = start - 1; i < s.len; i++) {
        s_son.data[j] = s.data[i];
        j++;
        s_son.len++;
    }
    j = 0;
    for (int i = start - 1; i < start + t.len; i++) {
        s.data[i] = t.data[j];
        j++;
    }
    j = 0;
    for (int i = start + t.len - 1; i < s.len + 1; i++) {
        s.data[i] = s_son.data[j];
        j++;
    }
    s.data[s.len + 1] = '\0';
    return OK;
}

//将串中[start,end]的串删除
Status DeleteString(String &s, int start, int end) {
    if(start<0 || end>s.len){
        return ERROR;
    }
    for(int i=(start-1);i<(s.len-end+start);i++){
        s.data[i]=s.data[i+end-start+1];
    }
    s.data[s.len-end+start-1]='\0';
    s.len=s.len-end+start-1;
    return OK;
}

//使用RK算法,在主串s中找出所有字串t的位置,位置放入arr数组中
Status GetIndexArrStringRK(String s,String t,int arr[]){

}


//将主串s中的s1串都替换成s2
Status ReplaceString(String &s,String s1,String s2){

}
