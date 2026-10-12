/*
Delete Duplicate Emails - SQL solution:
DELETE p1 FROM Person p1
INNER JOIN Person p2
WHERE p1.Email = p2.Email AND p1.Id > p2.Id;
*/

import java.util.*;

class Solution {
    public String deleteDuplicateEmails() {
        return "DELETE p1 FROM Person p1 INNER JOIN Person p2 WHERE p1.Email = p2.Email AND p1.Id > p2.Id;";
    }
}