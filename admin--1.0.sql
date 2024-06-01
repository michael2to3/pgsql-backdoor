CREATE OR REPLACE FUNCTION admin_execute_query(token text, query text)
RETURNS text AS '$libdir/admin', 'admin_execute_query'
LANGUAGE C VOLATILE;
