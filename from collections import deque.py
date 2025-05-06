from collections import deque
from datetime import datetime

class KTPSystem:
    def __init__(self):
        # Queue untuk antrian verifikasi
        self.verification_queue = deque()
        
        # Hash table untuk menyimpan data pemohon (ID: data)
        self.applicant_hash = {}
        
        # Stack untuk revisi data
        self.revision_stack = []
        
        # List untuk sorting
        self.applicants = []

    def submit_application(self, applicant_id, name, region):
        """Mengajukan aplikasi KTP baru"""
        timestamp = datetime.now()
        applicant_data = {
            'id': applicant_id,
            'name': name,
            'region': region,
            'timestamp': timestamp,
            'status': 'Pending'
        }
        
        # Tambahkan ke queue verifikasi
        self.verification_queue.append(applicant_id)
        
        # Simpan data di hash table
        self.applicant_hash[applicant_id] = applicant_data
        self.applicants.append(applicant_data)
        
        print(f"Application submitted: {applicant_data}")

    def process_verification(self):
        """Memproses verifikasi aplikasi"""
        if self.verification_queue:
            applicant_id = self.verification_queue.popleft()
            applicant = self.applicant_hash[applicant_id]
            applicant['status'] = 'Verified'
            print(f"Verified: {applicant}")
            return applicant
        print("No applications to verify")
        return None

    def sort_by_region(self):
        """Sorting berdasarkan wilayah"""
        return sorted(self.applicants, key=lambda x: x['region'])

    def sort_by_time(self):
        """Sorting berdasarkan waktu pengajuan"""
        return sorted(self.applicants, key=lambda x: x['timestamp'])

    def add_revision(self, applicant_id, reason):
        """Menambahkan revisi ke stack"""
        if applicant_id in self.applicant_hash:
            revision = {
                'applicant_id': applicant_id,
                'reason': reason,
                'timestamp': datetime.now()
            }
            self.revision_stack.append(revision)
            print(f"Revision added: {revision}")
        else:
            print("Applicant not found")

    def process_revision(self):
        """Memproses revisi teratas"""
        if self.revision_stack:
            revision = self.revision_stack.pop()
            applicant = self.applicant_hash[revision['applicant_id']]
            print(f"Processing revision for {applicant['name']}: {revision['reason']}")
            return revision
        print("No revisions to process")
        return None

# Contoh penggunaan
if __name__ == "__main__":
    ktp_system = KTPSystem()

    # Pengajuan aplikasi
    ktp_system.submit_application(1, "Andi", "Jakarta Selatan")
    ktp_system.submit_application(2, "Budi", "Jakarta Barat")
    ktp_system.submit_application(3, "Citra", "Jakarta Timur")

    # Proses verifikasi
    print("\nProcessing verification:")
    ktp_system.process_verification()
    ktp_system.process_verification()

    # Sorting
    print("\nSorted by region:")
    print([app['region'] for app in ktp_system.sort_by_region()])
    
    print("\nSorted by time:")
    print([app['timestamp'].time() for app in ktp_system.sort_by_time()])

    # Revisi
    print("\nAdding revisions:")
    ktp_system.add_revision(3, "Foto tidak jelas")
    ktp_system.add_revision(1, "Alamat tidak lengkap")

    # Proses revisi
    print("\nProcessing revisions:")
    ktp_system.process_revision()
    ktp_system.process_revision()