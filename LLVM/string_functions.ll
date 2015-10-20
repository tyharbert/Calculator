define i32 @main(){
    %OFFSET = alloca i32
    store i32 0, i32* %OFFSET
    %STRING_LOC = alloca [128 x i8] c"some string\00"
    %STRING_HEAD = getelementptr (i8* %STRING_LOC,i32 %OFFSET)
}

define i32 @strlen(i8* %STRING_HEAD) {
entry:

}