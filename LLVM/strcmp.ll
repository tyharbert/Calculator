; Tyler Harbert
; LLVM String Compare

; global string
@globstr = global [13xi8] c"input string\00"

; for printing
declare i32 @puts(i8*)

define i32 @main {

    ret 0
}

define i32 @strcmp(i8* %str1, i8* %str2){
    
    ; initialize an iterator at 0
    %offset = alloc i32
    store i32 0, i32* %offset
    
condit:
    ; load both of the first characters
    %idx = load i32* %offset
    %str3 = getelementptr inbounds i8* %str1, i32 %idx
    %char1 = load i8* %str3
    %str4 = getelementptr inbounds i8* %str2, i32 %idx
    %char2 = load i8* %str4
    
    ; check if left char is less (NULL is least)
    %1 = icmp ult i8 %char1, %char2
    br i1 %1, label %retneg, label %rightcheck
    
rightcheck:
    ; check if right char is less (NULL is least)
    %2 = icmp ult i8 %char2, %char1
    br i1 %2, label %retpos, label %endcheck
    
endcheck:
    ; check if either char is NULL, if so then we have equal strings (because we know the chars are equal)
    %3 = icmp eq i8 %char1, 0
    br i1 %3, label %retzero, label %body
    
body:
    ; increment the offset variable by 1
    %cur_offset = load i32* %offset
    %new_offset = add nsw i32 %cur_offset, 1
    store i32 %new_offset, i32* %offset
    br label %condit
    
retneg:
    ; return -1
    %ans1 = alloc i32
    store i32 -1, i32* %ans1
    ret i32 %ans1

retpos:
    ; return 1
    %ans2 = alloc i32
    store i32 1, i32* %ans2
    ret i32 %ans2

retzero:
    ; return 0
    %ans3 = alloc i32
    store i32 0, i32* %ans3
    ret i32 %ans3
}