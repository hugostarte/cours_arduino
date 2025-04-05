<?php
header('Content-Type: application/json');

$json = file_get_contents('php://input');
$data = json_decode($json, true);

error_log("Données reçues : " . print_r($data, true));

$temperature = isset($data['temperature']) ? floatval($data['temperature']) : null;
$humidity = isset($data['humidity']) ? floatval($data['humidity']) : null;

if ($temperature === null || $humidity === null) {
    http_response_code(400);
    echo json_encode(['error' => 'Données manquantes']);
    exit;
}

$donnees = [
    'temperature' => $temperature,
    'humidite' => $humidity,
    'date' => date('Y-m-d H:i:s')
];

$json_file = 'data_dht.json';
file_put_contents($json_file, json_encode($donnees, JSON_PRETTY_PRINT));

echo json_encode($donnees, JSON_PRETTY_PRINT);
?>