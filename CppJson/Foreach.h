#ifndef FOREACH_H
#define FOREACH_H
#include "LessBase.h"
#define Concat(V1,V2) V1##V2
#define ToChar(N) #N
#define ATTR(attr) attr

#define CatHelp(v1,v2) Concat(v1,v2)

#define CallFunc(Func,Param) Func(Param)

//#define Foreach_0(Func,Param,...) CallFunc(Func,Param)

#define Foreach_1(Func,Param,...) CallFunc(Func,Param)
                                                                  //ATTR(Foreach_0(Func,__VA_ARGS__)
#define Foreach_2(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_1(Func,__VA_ARGS__))
#define Foreach_3(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_2(Func,__VA_ARGS__))
#define Foreach_4(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_3(Func,__VA_ARGS__))
#define Foreach_5(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_4(Func,__VA_ARGS__))
#define Foreach_6(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_5(Func,__VA_ARGS__))
#define Foreach_7(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_6(Func,__VA_ARGS__))
#define Foreach_8(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_7(Func,__VA_ARGS__))
#define Foreach_9(Func,Param,...) CallFunc(Func,Param)\
                                                                  ATTR(Foreach_8(Func,__VA_ARGS__))
#define Foreach_10(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR( Foreach_9(Func,__VA_ARGS__))
#define Foreach_11(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_10(Func,__VA_ARGS__))
#define Foreach_12(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_11(Func,__VA_ARGS__))
#define Foreach_13(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_12(Func,__VA_ARGS__))
#define Foreach_14(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_13(Func,__VA_ARGS__))
#define Foreach_15(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_14(Func,__VA_ARGS__))
#define Foreach_16(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR( Foreach_15(Func,__VA_ARGS__))
#define Foreach_17(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_16(Func,__VA_ARGS__))
#define Foreach_18(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_17(Func,__VA_ARGS__))
#define Foreach_19(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_18(Func,__VA_ARGS__))
#define Foreach_20(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_19(Func,__VA_ARGS__))
#define Foreach_21(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_20(Func,__VA_ARGS__))
#define Foreach_22(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_21(Func,__VA_ARGS__))
#define Foreach_23(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_22(Func,__VA_ARGS__))
#define Foreach_24(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_23(Func,__VA_ARGS__))
#define Foreach_25(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_24(Func,__VA_ARGS__))
#define Foreach_26(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_25(Func,__VA_ARGS__))
#define Foreach_27(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_26(Func,__VA_ARGS__))
#define Foreach_28(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_27(Func,__VA_ARGS__))
#define Foreach_29(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_28(Func,__VA_ARGS__))
#define Foreach_30(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_29(Func,__VA_ARGS__))
#define Foreach_31(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_30(Func,__VA_ARGS__))
#define Foreach_32(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_31(Func,__VA_ARGS__))
#define Foreach_33(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_32(Func,__VA_ARGS__))
#define Foreach_34(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_33(Func,__VA_ARGS__))
#define Foreach_35(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_34(Func,__VA_ARGS__))
#define Foreach_36(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_35(Func,__VA_ARGS__))
#define Foreach_37(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(Foreach_36(Func,__VA_ARGS__))
#define Foreach_38(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,38))(Func,__VA_ARGS__))
#define Foreach_39(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,39))(Func,__VA_ARGS__))
#define Foreach_40(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,40))(Func,__VA_ARGS__))
#define Foreach_41(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,41))(Func,__VA_ARGS__))
#define Foreach_42(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,42))(Func,__VA_ARGS__))
#define Foreach_43(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,43))(Func,__VA_ARGS__))
#define Foreach_44(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,44))(Func,__VA_ARGS__))
#define Foreach_45(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,45))(Func,__VA_ARGS__))
#define Foreach_46(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,46))(Func,__VA_ARGS__))
#define Foreach_47(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,47))(Func,__VA_ARGS__))
#define Foreach_48(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,48))(Func,__VA_ARGS__))
#define Foreach_49(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,49))(Func,__VA_ARGS__))
#define Foreach_50(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,50))(Func,__VA_ARGS__))
#define Foreach_51(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,51))(Func,__VA_ARGS__))
#define Foreach_52(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,52))(Func,__VA_ARGS__))
#define Foreach_53(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,53))(Func,__VA_ARGS__))
#define Foreach_54(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,54))(Func,__VA_ARGS__))
#define Foreach_55(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,55))(Func,__VA_ARGS__))
#define Foreach_56(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,56))(Func,__VA_ARGS__))
#define Foreach_57(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,57))(Func,__VA_ARGS__))
#define Foreach_58(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,58))(Func,__VA_ARGS__))
#define Foreach_59(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,59))(Func,__VA_ARGS__))
#define Foreach_60(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,60))(Func,__VA_ARGS__))
#define Foreach_61(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,61))(Func,__VA_ARGS__))
#define Foreach_62(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,62))(Func,__VA_ARGS__))
#define Foreach_63(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,63))(Func,__VA_ARGS__))
#define Foreach_64(Func,Param,...) CallFunc(Func,Param) \
                                                                  ATTR(CatHelp(Foreach_,Concat(LESS_,64))(Func,__VA_ARGS__))


#define QUICKCHECK(Number,Func,Param,...)  CallFunc(Func,Param) ATTR(CatHelp(Foreach_,Concat(LESS_,Number))(Func,__VA_ARGS__))

#define FL_ARG_COUNT(...) ATTR(FL_INTERNAL_ARG_COUNT_PRIVATE(0, __VA_ARGS__,\
        64, 63, 62, 61, 60, \
        59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
        49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
        39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
        29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
        19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
        9,  8,  7,  6,  5,  4,  3,  2,  1,  0))

#define FL_INTERNAL_ARG_COUNT_PRIVATE(\
        _0,  _1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9, \
        _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, \
        _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, \
        _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, \
        _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, \
        _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, \
        _60, _61, _62, _63, _64, N, ...) N
#define N_Number(...)  ATTR(FL_ARG_COUNT(__VA_ARGS__))

#define For_Func(Number,Func,...) ATTR(Concat(Foreach_,Number)(Func,__VA_ARGS__))

#define For_Each(Func,...) ATTR(For_Func(N_Number(__VA_ARGS__) ,Func,__VA_ARGS__))

#endif // FOREACH_H
