/*Déclaration des constante relative à l'analyse syntaxique*/
/*definitions variables*/
const char TOKEN_VAR_1[]="^\\$.*=\\ <\\?.*\\?>$";
const char TOKEN_VAR_2[]="^\\$.*=<\\?.*\\?>$";
const char TOKEN_VAR_3[]="^\\$.*=.*$";
const char TOKEN_VAR_START_1[]="^\\$.*=\\ <\\?.*$";
const char TOKEN_VAR_START_2[]="^\\$.*=<\\?.*$";
const char TOKEN_VAR_END_1_2[]="\\?>$";
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
