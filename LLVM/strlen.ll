; Tyler Harbert
; LLVM String Length

; global string
@globstr = global [13xi8] c"input string\00"

; for printing
declare i32 @puts(i8*)

define i32 @main {

    ret 0
}

define i32 @strlen(i8* %str){
    
    ; initialize an iterator at 0
    %offset = alloc i32
    store i32 0, i32* %offset
    
condi
    ; load the current character
    %idx = load i32* %offset
    %str1 = getelementptr inbounds i8* %str, i32 %idx
    %char = load i8* %str1
    
    ; check if the current char is NULL
    %res = icmp eq i8 %char, 0
    br i1 %res, label %end, label %body
    
body:
    ; increment the offset variable by 1
    %cur_offset = load i32* %offset
    %new_offset = add nsw i32 %cur_offset, 1
    store i32 %new_offset, i32* %offset
    br label %condit
    
end:
    ; return the index that the NULL was found at
    ret i32 %idx
}