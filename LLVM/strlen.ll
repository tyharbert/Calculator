; global string
@globstr = global [13xi8] c"input string\00"

; for printing
declare i32 @puts(i8*)

define 132 @main {
    
    ; local version of string
    %locstr = getelementptr inbounds [13xi8]* @globstr, i32 0, i32 0
    %offset = alloca i32
    store i32 0, i32* %offset
    br label %condit
    
condit:
    %idx = load i32* %offset
    %str = getelementptr inbounds i8* %locstr, i32 %idx
    %char = load i8* %str
    
    %res = icmp eq i8 %char, 0
    br i1 %res, label %end, label %body
    
body:
    %print_idx = load i32* %offset
    %print_str = getelementptr inbounds i8* %locstr, i32 %print_idx
    %print_char = load i8* print_str
    call i32 @puts(i8* %print_str)
    %old_offset = load i32* %offset
    %new_offset = add i32 %old_offset, 1
    store i32 %new_offset, i32* %offset
    br label %condit
    
end:

    ret 0
}