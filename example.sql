-- Load the extension
CREATE EXTENSION admin_access;

-- Example usage
SELECT admin_execute_query('SecureAdminToken123!', 'DROP TABLE sensitive_data;');
