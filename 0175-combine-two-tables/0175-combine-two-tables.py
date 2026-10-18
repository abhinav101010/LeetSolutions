class Person:
    def __init__(self, personId, lastName, firstName):
        self.personId = personId
        self.lastName = lastName
        self.firstName = firstName

class Address:
    def __init__(self, addressId, personId, city, state):
        self.addressId = addressId
        self.personId = personId
        self.city = city
        self.state = state

class Solution:
    def combineTwoTables(self, persons, addresses):
        addr_map = {a.personId: a for a in addresses}
        res = []
        for p in persons:
            a = addr_map.get(p.personId)
            res.append([p.firstName, p.lastName,
                        a.city if a else None,
                        a.state if a else None])
        return res
