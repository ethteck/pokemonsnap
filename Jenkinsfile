pipeline {
    agent {
        label 'pokemonsnap'
    }

    stages {
        stage('Setup') {
            steps {
                sh 'cp /usr/local/etc/roms/pokemonsnap.us.z64 pokemonsnap.z64'
                sh 'pip install -U -r requirements.txt --break-system-packages'
                sh 'cargo install pigment64'
                sh './configure.py --setup'
                sh './configure.py'
            }
        }
        stage('Build') {
            steps {
                sh "bash -o pipefail -c 'ninja 2>&1 | tee build_log.txt'"
            }
        }
        stage('Report Progress') {
            steps {
                sh 'python3 -m mapfile_parser objdiff_report us_report.json'
                // sh 'zip us_report.zip report.json'
            }
        }
    }
    post {
        always {
            archiveArtifacts artifacts: '*_report.json', fingerprint: true
            cleanWs()
        }
    }
}
