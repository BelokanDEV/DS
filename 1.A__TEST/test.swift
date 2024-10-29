// Queue를 제네릭으로 구현하여 다양한 타입을 처리할 수 있게 함
struct Queue<T> {
    // 큐에 들어갈 요소들을 저장하는 배열
    private var elements: [T] = []
    
    // 큐가 비었는지 확인하는 계산 속성
    var isEmpty: Bool {
        return elements.isEmpty
    }
    
    // 큐의 첫 번째 요소를 확인하는 계산 속성
    var front: T? {
        return elements.first
    }
    
    // 큐에 요소를 추가하는 메서드
    mutating func enqueue(_ element: T) {
        elements.append(element)
    }
    
    // 큐에서 요소를 제거하고 반환하는 메서드 (옵셔널로 반환)
    mutating func dequeue() -> T? {
        return isEmpty ? nil : elements.removeFirst()
    }
}
// 정수를 저장하는 큐 생성
var intQueue = Queue<Int>()

intQueue.enqueue(10)  // 10을 큐에 추가
intQueue.enqueue(20)  // 20을 큐에 추가
intQueue.enqueue(30)  // 30을 큐에 추가

print(intQueue.front ?? "큐가 비어 있습니다.")  // 출력: 10 (큐의 첫 번째 요소)

if let dequeuedElement = intQueue.dequeue() {
    print("Dequeued: \(dequeuedElement)")  // 출력: Dequeued: 10 (첫 번째 요소 제거)
}

print(intQueue.front ?? "큐가 비어 있습니다.")  // 출력: 20 (이제 첫 번째 요소는 20)
