import './assets/less/main-theme.less'
import PageRouter from 'page-router';
import Helmet from 'react-helmet';
import { HashRouter } from 'react-router-dom';

const App = () => {

  return (
    <>
      <Helmet titleTemplate="%s | Linux 101" defer={false}>
        <title>Loading</title>
      </Helmet>

      <HashRouter>
        <PageRouter />
      </HashRouter>

    </>
  )
};


export default App;
