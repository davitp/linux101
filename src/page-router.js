import React, { lazy, Suspense } from 'react';
import { Route, Routes } from 'react-router-dom';
import LoadingPage from 'pages/_loading';
import MainLayout from 'layouts/main-layout';

const page = (elem) => (
    <Suspense fallback={<LoadingPage />}>
        {elem}
    </Suspense>
);

const IndexPage = lazy(() => import('pages/index'));
const NotFoundPage = lazy(() => import('pages/not-found'));

const IntroductionTopicPage = lazy(() => import('pages/topics/introduction'));


const PageRouter = () => {
    return (
        <Routes>
            <Route element={<MainLayout />}>
                <Route index element={page(<IndexPage />)} />
                <Route path="topics">
                <Route path="introduction" element={page(<IntroductionTopicPage />)} />
            </Route>
            </Route>
            <Route path="/not-found" element={page(<NotFoundPage />)} />
            <Route path="*" element={page(<NotFoundPage />)} />
        </Routes>
    )
}

export default PageRouter;
