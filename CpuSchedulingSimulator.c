#include <stdio.h>

// 프로세스 구조체 정의
typedef struct {
    int arrival_time; // 도착 시간
    int burst_time;   // 실행 시간
} Process;

// FCFS 스케줄링 함수
void fcfs(Process processes[], int n) {
    int completion_time[n]; // 완료 시간
    int turnaround_time[n]; // 반환 시간
    int waiting_time[n];    // 대기 시간
    
    int current_time = 0; // 현재 시간
    
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        
        completion_time[i] = current_time + processes[i].burst_time;
        turnaround_time[i] = completion_time[i] - processes[i].arrival_time;
        waiting_time[i] = turnaround_time[i] - processes[i].burst_time;
        
        current_time = completion_time[i];
    }
    
    // 결과 출력
    printf("FCFS Scheduling\n");
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n"); //프로세스, 도착시간, 실행시간, 완료시간, 반환시간, 대기시간
    
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i].arrival_time, processes[i].burst_time, completion_time[i], turnaround_time[i], waiting_time[i]);
    }
}

// SJF 스케줄링 함수
void sjf(Process processes[], int n) {
    int completion_time[n]; // 완료 시간
    int turnaround_time[n]; // 반환 시간
    int waiting_time[n];    // 대기 시간
    
    int remaining_time[n]; // 남은 실행 시간
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }
    
    int completed = 0; // 완료된 프로세스 수
    
    int current_time = 0; // 현재 시간
    
    while (completed < n) {
        int shortest_job = -1; // 실행 시간이 가장 짧은 프로세스의 인덱스
        
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && (shortest_job == -1 || remaining_time[i] < remaining_time[shortest_job])) {
                shortest_job = i;
            }
        }
        
        if (shortest_job == -1) {
            current_time++;
            continue;
        }
        
        completion_time[shortest_job] = current_time + remaining_time[shortest_job];
        turnaround_time[shortest_job] = completion_time[shortest_job] - processes[shortest_job].arrival_time;
        waiting_time[shortest_job] = turnaround_time[shortest_job] - processes[shortest_job].burst_time;
        
        remaining_time[shortest_job] = 0;
        current_time = completion_time[shortest_job];
        completed++;
    }
    
    // 결과 출력
    printf("\nSJF Scheduling\n");
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i].arrival_time, processes[i].burst_time, completion_time[i], turnaround_time[i], waiting_time[i]);
    }
}

// SRT 스케줄링 함수
void srt(Process processes[], int n) {
    int completion_time[n]; // 완료 시간
    int turnaround_time[n]; // 반환 시간
    int waiting_time[n];    // 대기 시간
    
    int remaining_time[n]; // 남은 실행 시간
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }
    
    int completed = 0; // 완료된 프로세스 수
    
    int current_time = 0; // 현재 시간
    
    while (completed < n) {
        int shortest_job = -1; // 실행 시간이 가장 짧은 프로세스의 인덱스
        
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && remaining_time[i] > 0 && (shortest_job == -1 || remaining_time[i] < remaining_time[shortest_job])) {
                shortest_job = i;
            }
        }
        
        if (shortest_job == -1) {
            current_time++;
            continue;
        }
        
        remaining_time[shortest_job]--;
        current_time++;
        
        if (remaining_time[shortest_job] == 0) {
            completion_time[shortest_job] = current_time;
            turnaround_time[shortest_job] = completion_time[shortest_job] - processes[shortest_job].arrival_time;
            waiting_time[shortest_job] = turnaround_time[shortest_job] - processes[shortest_job].burst_time;
            
            completed++;
        }
    }
    
    // 결과 출력
    printf("\nSRT Scheduling\n");
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i].arrival_time, processes[i].burst_time, completion_time[i], turnaround_time[i], waiting_time[i]);
    }
}

int main() {
    // 프로세스 배열
    Process processes[] = {
        {0, 5},
        {2, 3},
        {4, 1},
        {5, 4},
        {6, 2}
    };
    
    int n = sizeof(processes) / sizeof(processes[0]);
    
    // 각 스케줄링 알고리즘 실행
    fcfs(processes, n);
    sjf(processes, n);
    srt(processes, n);
    
    return 0;
}
