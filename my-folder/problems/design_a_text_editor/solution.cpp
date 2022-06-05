class TextEditor {
public:
    string str;
    int cursor = 0;
    TextEditor() {
        
    }
    
    void addText(string text) {
        str.insert(cursor,text);
        cursor+=text.length();
    }
    
    int deleteText(int k) {
        
        if(cursor<=k)
        {
            int y = cursor;
            str=str.substr(cursor);
            cursor = 0;
            return y;
        }
         
        str.erase(cursor-k , k);
        cursor-=k; 
        return k;
    }
    
    string cursorLeft(int k) {
        cursor=cursor-k;
        if(cursor<0)
        {
            cursor=0;
        }
        int minn = min(10,cursor);
        return str.substr(cursor-minn,minn);
    }
    
    string cursorRight(int k) {
        cursor=cursor+k;
        if(cursor>str.length())
        {
            cursor = str.length();
        }
        int minn = min(10,cursor);
        return str.substr(cursor-minn,minn);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */