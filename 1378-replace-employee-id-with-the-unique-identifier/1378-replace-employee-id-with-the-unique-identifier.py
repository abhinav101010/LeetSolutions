class Solution:
    def get_employee_names(self, employees, unis):
        m = {u['id']: u['unique_id'] for u in unis}
        return [[m.get(e['id']), e['name']] for e in employees]
