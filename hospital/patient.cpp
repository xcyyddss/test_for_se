#include "patient.h"

void Patient::check_diagnosis(){
    QLinkedList<QLinkedList<QString>> diagnosis_list;
    QString condition = "patientId = '"+this->get_ID()+"'";
    diagnosis_list = read_data("Diagnosis",condition);
    diagnosis_num = diagnosis_list.size();
    diagnosis = new Diagnosis* [diagnosis_num];
    int idx = 0;
    for(QLinkedList<QString> &list: diagnosis_list){
        diagnosis[idx] = new Diagnosis(list);
        idx++;
    }
}

void Patient::check_prescription(){
    QLinkedList<QLinkedList<QString>> prescription_list;
    QString condition = "patientId = '"+this->get_ID()+"'";
    prescription_list = read_data("Prescription",condition);
    prescription_num = prescription_list.size();
    prescription = new Prescription* [prescription_num];
    int idx = 0;
    for(QLinkedList<QString> &list: prescription_list){
        prescription[idx] = new Prescription(list);
        idx++;
    }
}

void Patient::check_appointment(){
    QLinkedList<QLinkedList<QString>> appointment_list;
    QString condition = "patientId = '"+this->get_ID()+"'";
    appointment_list = read_data("Appointment",condition);
    appointment_num = appointment_list.size();
    appointment = new Appointment* [appointment_num];
    int idx = 0;
    for(QLinkedList<QString> &list: appointment_list){
        appointment[idx] = new Appointment(list);
        idx++;
    }
}

void Patient::check_doctor(){
    QLinkedList<QLinkedList<QString>> doctor_list;
    QString condition = "identity = 'doctor'";
    doctor_list = read_data("Person",condition);
    doctor_num = doctor_list.size();
    doctor = new Person* [doctor_num];
    int idx = 0;
    for(QLinkedList<QString> &list: doctor_list){
        doctor[idx] = new Person(list);
        idx++;
    }
}

void Patient::make_appointment(QString time, QString doctorId){
    QLinkedList<QString> data;
    data<<time<<this->get_ID()<<doctorId<<QString("not_finished");
    insert_data("Appointment",data);
    check_appointment();
}


QLinkedList<QLinkedList<QString>> Patient::get_diagnosis(QString date){
    QLinkedList<QLinkedList<QString>> out_list;
    if(date == ""){
        for(int i{};i<diagnosis_num;i++){
            out_list<<diagnosis[i]->get_details();
        }
    }
    else{
        for(int i{};i<diagnosis_num;i++){
            if(diagnosis[i]->get_date() == date){
                out_list<<diagnosis[i]->get_details();
            }
        }
    }
    return out_list;
}

QLinkedList<QLinkedList<QString>> Patient::get_prescription(QString date){
    QLinkedList<QLinkedList<QString>> out_list;
    if(date == ""){
        for(int i{};i<prescription_num;i++){
            out_list<<prescription[i]->get_details();
        }
    }
    else{
        for(int i{};i<prescription_num;i++){
            if(prescription[i]->get_date() == date){
                out_list<<prescription[i]->get_details();
            }
        }
    }
    return out_list;
}

QLinkedList<QLinkedList<QString>> Patient::get_appointment(QString date){
    QLinkedList<QLinkedList<QString>> out_list;
    if(date == ""){
        for(int i{};i<appointment_num;i++){
            out_list<<appointment[i]->get_details();
        }
    }
    else{
        for(int i{};i<appointment_num;i++){
            if(appointment[i]->get_time().contains(date)){
                out_list<<appointment[i]->get_details();
            }
        }
    }
    return out_list;
}

QLinkedList<QLinkedList<QString>> Patient::get_doctor(QString word){
    QLinkedList<QLinkedList<QString>> out_list;
    if(word == ""){
        for(int i{};i<doctor_num;i++){
            out_list<<doctor[i]->get_details();
        }
    }
    else{
        for(int i{};i<doctor_num;i++){
            if(doctor[i]->get_status().contains(word)){
                out_list<<doctor[i]->get_details();
            }
        }
    }
    return out_list;
}
