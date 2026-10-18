import java.util.*;

class Patient {
    int patient_id;
    String patient_name;
    String conditions;
    Patient(int patient_id, String patient_name, String conditions) {
        this.patient_id = patient_id; this.patient_name = patient_name; this.conditions = conditions;
    }
}

class Solution {
    public List<List<String>> patientsWithCondition(List<Patient> patients) {
        List<List<String>> ans = new ArrayList<>();
        for (Patient p : patients) {
            boolean match = false;
            if (p.conditions != null && p.conditions.startsWith("DIAB1")) match = true;
            if (!match && p.conditions != null && p.conditions.contains(" DIAB1")) match = true;
            if (match) ans.add(Arrays.asList(String.valueOf(p.patient_id), p.patient_name, p.conditions));
        }
        return ans;
    }
}
