class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if len(ransomNote) < 1 or len(magazine) > 10**5:
            return False
        listNote = list(ransomNote)
        listMag = list(magazine)
        for noteEle in listNote:
            if noteEle in listMag:
                listMag.remove(noteEle)
            else:
                return False;
        return True
