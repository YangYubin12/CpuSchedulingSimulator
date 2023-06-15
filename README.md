# ✅ Cpu Scheduling Simulator
프로세스 관리-CPU 스케줄링 시뮬레이터

## CPU 스케줄링 시뮬레이터
FCFS, SJF, SRT 스케줄링으로 구현하였다

## 스케줄링 설명
### - FCFS 스케줄링
* 준비 큐에 도착한 순서대로 CPU를 할당하는 비선점형 방식
* 한 번 실행되면 그 프로세스가 끝나야만 다음 프로세스를 실행할 수 있음
* 큐가 하나라 모든 프로세스는 우선 순위가 동일

### - SJF 스케줄링
* 준비 큐에 있는 프로세스 중에서 실행 시간이 가장 짧은 작업부터 CPU를 할당하는 비선점형 방식
* 최단 작업 우선 스케줄링이라고도 함

### - SRT 스케줄링
- 가장 작업 시간이 짧은 프로세스를 먼저 실행하는 스케줄링 알고리즘
- CPU 이용률을 높이고, 응답 시간을 줄여 전반적인 성능을 향상시킨다 
- 따라서 작업의 대기 시간이 짧아지며, 프로세스들이 더 빠르게 실행된다

## 구현
[구현 코드](https://github.com/YangYubin12/CpuSchedulingSimulator/blob/master/CpuSchedulingSimulator.c)

## 실행 결과
<img width="618" alt="스크린샷 2023-06-14 오후 1 17 35" src="https://github.com/YangYubin12/CpuSchedulingSimulator/assets/102217712/e0008807-1751-4144-a16e-b439aacfdae5">
