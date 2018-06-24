RULE(ws  ,B( X(isspace(any())) R(ws)   ) B( {T=0;} ));
RULE(ynum,B( X(isdigit(any())) R(ynum) ) B( ));
RULE(anum,B( X(isalnum(any())) ) B( C('$') ))
RULE(xid ,B( R(anum) R(xid)  ) B( ));
RULE(xnum,B( X(isdigit(any())) R(ynum) ));
RULE(xstr,B( C('"') ) B( C('\\') R(any) R(xstr) ) B( NC('"') R(any) R(xstr) ));
RULE(num, B( C('-') R(xnum) {$$=tok();} ) B( R(xnum) {$$=tok();} ));
RULE(str, B( C('"') R(xstr) {$$=tok();} ));
RULE(id,  B( X(isalpha(any())) R(xid) {$$=tok();} ) B( C('$') R(xid) {$$=tok();} ));
RULE(atum,B( R(id) ) B( R(num) ) B( R(str) )
     B( C('\'') C('\\') R(any) C('\'') {$$=tok();} )
     B( C('\'')         R(any) C('\'') {$$=tok();} ));
RULE(xlst,B( R(ws) R(xpr) R(xlst) {$$=cons($2,$3);} ) B( R(ws) {$$=EOL;} ));
RULE(xpr, B( R(id) C('(') R(xlst) C(')') {$$=cons($1,$3);} ) B( R(atum) ));
RULE(xxpr,B( R(id) C('=') R(xpr) {$$=cons($2,cons($1,$3) );} ) B( R(xpr) ));
RULE(trm, B( R(xpr) ) B( C('{') R(xxpr) C('}') ) )
RULE(tlst,B( R(ws)   R(trm) R(tlst) {$$=cons($2,$3);} ) B( R(ws) {$$=EOL;} ));
RULE(olst,B( R(tlst) C('|') R(olst) {$$=cons($1,$3);} ) B( R(tlst) ));
RULE(rule,B( R(ws)   C('/')  C('/') R(id) R(olst) {$$=cons($4,$5);} ));
RULE(rlst,B( R(rule) R(rlst) {$$=cons($1,$2);} ) B( R(ws) R(eof) {$$=EOL;} ));
