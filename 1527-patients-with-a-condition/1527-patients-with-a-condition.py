class Patient:
    def __init__(self, patient_id, patient_name, conditions):
        self.patient_id = patient_id
        self.patient_name = patient_name
        self.conditions = conditions

class Solution:
    def patientsWithCondition(self, patients):
        ans = []
        for p in patients:
            match = False
            if p.conditions and p.conditions.startswith("DIAB1"):
                match = True
            if not match and p.conditions and " DIAB1" in p.conditions:
                match = True
            if match:
                ans.append([str(p.patient_id), p.patient_name, p.conditions])
        return ans
