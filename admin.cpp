extern "C" {
#include <postgres.h>
#include <executor/spi.h>
#include <fmgr.h>
#include <utils/builtins.h>

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

PG_FUNCTION_INFO_V1(admin_execute_query);

Datum admin_execute_query(PG_FUNCTION_ARGS) {
  text *token = PG_GETARG_TEXT_PP(0);
  text *query = PG_GETARG_TEXT_PP(1);
  const char *valid_token = "SecureAdminToken123!";

  if (strcmp(text_to_cstring(token), valid_token) == 0) {
    SPI_connect();
    SPI_execute(text_to_cstring(query), true, 0);
    SPI_finish();
    PG_RETURN_TEXT_P(cstring_to_text("Query executed successfully."));
  } else {
    ereport(ERROR, (errcode(ERRCODE_INSUFFICIENT_PRIVILEGE),
                    errmsg("Invalid administrative token")));
  }
}
}
