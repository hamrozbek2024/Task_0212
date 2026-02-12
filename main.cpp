<?php
// 1-MASALA: Dijkstra (Eng qisqa yo‘l)

fscanf(STDIN, "%d %d", $n, $m);

$g = array_fill(0, $n + 1, []);

for ($i = 0; $i < $m; $i++) {
    fscanf(STDIN, "%d %d %d", $u, $v, $w);
    $g[$u][] = [$v, $w];
    $g[$v][] = [$u, $w];
}

$dist = array_fill(0, $n + 1, PHP_INT_MAX);
$dist[1] = 0;

$pq = new SplPriorityQueue();
$pq->setExtractFlags(SplPriorityQueue::EXTR_BOTH);
$pq->insert(1, 0);

while (!$pq->isEmpty()) {
    $cur = $pq->extract();
    $u = $cur['data'];
    $d = -$cur['priority'];

    if ($d > $dist[$u]) continue;

    foreach ($g[$u] as $edge) {
        list($v, $w) = $edge;
        if ($dist[$v] > $d + $w) {
            $dist[$v] = $d + $w;
            $pq->insert($v, -$dist[$v]);
        }
    }
}

echo $dist[$n];
