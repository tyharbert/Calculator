; Tyler Harbert
; LLVM String Compare

; global string
@globstr = global [13xi8] c"input string\00"

; for printing
declare i32 @puts(i8*)

define i32 @main {

    ret 0
}

define i1 @strcmp(i8* %str1, i8* %str2){

    %len1 = call i32 @strlen(i8* %str1)
    %len2 = call i32 @strlen(i8* %str2)
    %1 = icmp eq i8 %len1, %len2
    %offset = alloc i32
    store i32 0, i32* %offset
    br i1 %1, label %condit, label %fail
    
condit:
    %idx = load i32* %offset
    %str3 = getelementptr inbounds i8* %str1, i32 %idx
    %char1 = load i8* %str3
    %str4 = getelementptr inbounds i8* %str2, i32 %idx
    %char2 = load i8* %str4
    
    %2 = icmp eq i8 %char1, 0
    br i1 %2, label %pass, label %cont
cont:
    %3 = icmp eq i8 %char1, %char2
    br i1 %3, label %body, label %fail
    
body:
    %cur_offset = load i32* %offset
    %new_offset = add nsw i32 %cur_offset, 1
    store i32 %new_offset, i32* %offset
    br label %condit
    
fail:
    %ans1 = alloc i1
    store i1 0, i1* %ans1
    ret i1 %ans1

pass:
    %ans2 = alloc i1
    store i1 1, i1* %ans2
    ret i1 %ans2
}