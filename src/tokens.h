/*Déclaration des constante relative à l'analyse syntaxique*/
/*definitions variables*/
const char TOKEN_VAR_1[]="^\\$.*=\\ <\\?.*\\?>$";
const char TOKEN_VAR_2[]="^\\$.*=<\\?.*\\?>$";
const char TOKEN_VAR_3[]="^\\$.*=.*$";
const char TOKEN_VAR_START_1[]="^\\$.*=\\ <\\?.*$";
const char TOKEN_VAR_START_2[]="^\\$.*=<\\?.*$";
const char TOKEN_VAR_END_1_2[]="\\?>$";
/*definitions variables de session*/
const char TOKEN_VAR_SESSION_1[]="^s\\$.*=\\ <\\?.*\\?>$";
const char TOKEN_VAR_SESSION_2[]="^s\\$.*=<\\?.*\\?>$";
const char TOKEN_VAR_SESSION_3[]="^s\\$.*=.*$";
const char TOKEN_VAR_SESSION_START_1[]="^s\\$.*=\\ <\\?.*$";
const char TOKEN_VAR_SESSION_START_2[]="^s\\$.*=<\\?.*$";
const char TOKEN_VAR_SESSION_NAME_1[]="(\\$.*=)";
/*nom variable*/
const char TOKEN_VAR_NAME_1[]="(^\\$.*=)";
const char TOKEN_VAR_NAME_2[]="([_[:alnum:]]+)";

/*file upload*/
const char TOKEN_VAR_NAME_FILEUPLOAD_1[]="(; name=\"[_\\.[:alnum:]]+)";
const char TOKEN_VAR_FILENAME_FILEUPLOAD_1[]="(; filename=\".*\")";
const char TOKEN_VAR_TYPE_FILEUPLOAD_1[]="(^Content-Type: .*)";

/*definitions conditions*/
const char TOKEN_IF_1[]="^if\\(.*\\)\\{";
const char TOKEN_IF_2[]="^if\\ *\\(.*\\)\\ *\\{";
const char TOKEN_IF_3[]="^if\\(.*\\)\\ *\\{";
const char TOKEN_IF_4[]="^if\\ *\\(.*\\)\\{";
const char TOKEN_ELSE_1[]="^\\}else\\{";
const char TOKEN_ELSE_2[]="^\\}\\ *else\\ *\\{";
const char TOKEN_ELSE_3[]="^\\}else\\ *\\{";
const char TOKEN_ELSE_4[]="^\\}\\ *else\\{";
const char TOKEN_IF_ELSE_END_1[]="^\\}"; 

/*definitions while*/
const char TOKEN_WHILE_1[]="^while\\(.*\\)\\{";
const char TOKEN_WHILE_2[]="^while\\ *\\(.*\\)\\ *\\{";
const char TOKEN_WHILE_3[]="^while\\(.*\\)\\ *\\{";
const char TOKEN_WHILE_4[]="^while\\ *\\(.*\\)\\{";

/*definitions for*/
const char TOKEN_FOR_1[]="^for\\(.*\\)\\{";
const char TOKEN_FOR_2[]="^for\\ *\\(.*\\)\\ *\\{";
const char TOKEN_FOR_3[]="^for\\(.*\\)\\ *\\{";
const char TOKEN_FOR_4[]="^for\\ *\\(.*\\)\\{";

/*definitions marker*/
const char TOKEN_MARKER_SET[]="^:.*";
const char TOKEN_MARKER_GET[]="^->.*";

/*definitions function*/
const char TOKEN_INCLUDE_1[]="^include\\(.*\\)";
const char TOKEN_INCLUDE_2[]="^include\\ *\\(.*\\)";
const char TOKEN_GOTO_1[]="^goto\\(.*\\)";
const char TOKEN_GOTO_2[]="^goto\\ *\\(.*\\)";
